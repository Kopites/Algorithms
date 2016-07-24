#include <iostream>
#include <cstdio>

using namespace std;
const int N = 1e5 + 5;

int n, a[N];

int Max(int arr[], int n) {
    int ma = arr[0];
    for (int i = 1; i < n; i ++)
        ma = max(ma, arr[i]);
    return ma;
}
void CountSort(int arr[], int n, int exp) {
    int out[N], count[10] = { 0 };
    for (int i = 0; i < n; i ++)
        ++ count[(arr[i] / exp) % 10];
    for (int i = 1; i < 10; i ++)
        count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; i --) {
        out[count[(arr[i] / exp) % 10] - 1] = arr[i];
        -- count[(arr[i] / exp) % 10];
    }
    for (int i = 0; i < n; i ++)
        arr[i] = out[i];
}
void RadixSort(int arr[], int n) {
    int m = Max(arr, n);
    int exp = 1;
    while (m > 0) {
        CountSort(arr, n, exp);
        exp *= 10;
        m /= 10;
    }
}
int main() {
    freopen("RadixSort.inp", "r", stdin);
    cin >> n;
    int cntNeg = 0, cntPos = 0, neg[N];
    for (int i = 0; i < n; i ++) {
        int x;
        cin  >> x;
        if (x < 0) neg[cntNeg ++] = x;
        else a[cntPos ++] = x;
    }
    for (int i = 0; i < cntNeg; i ++)
        neg[i] = -neg[i];
    RadixSort(neg, cntNeg);
    for (int i = cntNeg - 1; i >= 0; i --)
        cout << -neg[i] << " ";
    RadixSort(a, cntPos);
    for (int i = 0; i < cntPos; i ++)
        cout << a[i] << " ";
    cout << endl;
    return 0;
}
