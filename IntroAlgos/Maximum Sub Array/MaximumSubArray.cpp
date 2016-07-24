#include <iostream>
#include <cstdio>

using namespace std;
const int OO = 1e9 + 7;
const int N  = 1e5 + 5;

int n, a[N];
/** Brute forces Algorithms, Complexity: O(n^2) */
int BruteForces(int n, int a[]) {
    int ans = -OO;
    for (int i = 1; i <= n; i ++) {
        int temp = 0;
        for (int j = i; j <= n; j ++) {
            temp += a[j];
            ans = max(ans, temp);
        }
    }
    return ans;
}

/** Divide and Conquer solution, Complexity:O(nlog(n)) */
struct Result {
    int max_left;
    int max_right;
    int sum;
};

Result MaxCrossSubArray(int a[], int low, int mid, int high) {
    Result ret;
    int left_sum = -OO;
    int sum = 0;
    for (int i = mid; i >= low; i --) {
        sum += a[i];
        if (sum > left_sum) {
            left_sum = sum;
            ret.max_left = i;
        }
    }
    int right_sum = -OO;
    sum = 0;
    for (int j = mid + 1; j <= high; j ++) {
        sum += a[j];
        if (sum > right_sum) {
            right_sum = sum;
            ret.max_right = j;
        }
    }
    ret.sum = left_sum + right_sum;
    return ret;
}
Result MaximumMaxArray(int a[], int low, int high) {
    Result ret;
    Result left, cross, right;
    if (low == high) {
        ret.max_left = low, ret.max_right = high,
        ret.sum = a[low];
    } else {
        int mid = (low + high) / 2;
        left  = MaximumMaxArray(a, low, mid);
        right = MaximumMaxArray(a, mid + 1, high);
        cross = MaxCrossSubArray(a, low, mid, high);
        if (left.sum > right.sum && left.sum > cross.sum)
            ret = left;
        else if (right.sum > left.sum && right.sum > cross.sum)
            ret = right;
        else ret = cross;
    }
    return ret;
}
void DCSolve(int a[], int low, int high) {
    Result res = MaximumMaxArray(a, low, high);
    cout << res.sum << endl;
    for (int id = res.max_left; id <= res.max_right; id ++)
        cout << a[id] << " ";
    cout << endl;
}
int DPSolve(int a[], int low, int high) {
    int max_ending_here = 0, max_so_far = 0;
    for (int i = low; i <= high; i ++) {
        max_ending_here = max(max_ending_here + a[i], 0);
        max_so_far = max(max_so_far, max_ending_here);
    }
    return max_so_far;
}

void MaximumMaxArrayLinear(int n, int a[]) {
    int low, high, max_sum = -OO;
    int ending_here_sum = -OO, ending_here_high, ending_here_low;
    for (int j = 1; j <= n; j ++ ) {
        ending_here_high = j;
        if (ending_here_sum > 0)
            ending_here_sum += a[j];
        else {
            ending_here_low = j;
            ending_here_sum = a[j];
        }
        if (ending_here_sum > max_sum) {
            max_sum = ending_here_sum;
            low  = ending_here_low;
            high = ending_here_high;
        }
    }
    cout << max_sum << endl;
    for (int i = low; i <= high; i ++)
        cout << a[i] << " ";
    cout << endl;
}
int main() {
    freopen("MaximumSubArray.inp", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    cout << "Brute: \n\n" << BruteForces(n, a) << endl ;
    cout << "DC: \n" << endl;
    DCSolve(a, 1, n);
    cout << endl;
   // cout << "DP: \n" << endl;
  //  cout << DPSolve(a, 1, n) << endl << endl;
    MaximumMaxArrayLinear(n, a);
    return 0;
}
