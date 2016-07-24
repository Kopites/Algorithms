#include <iostream>
#include <cstdio>

using namespace std;
const int N = 1e5 + 5;


int Partition(int A[], int p, int r) {
    int x = A[r];
    int i = p - 1;
    for (int j = p; j <= r - 1; j ++) {
        if (A[j] <= x) {
            ++ i;
            swap(A[i], A[j]);
        }
    }
    swap(A[i + 1], A[r]);
    return (i + 1);
}

void QuickSort(int A[], int p, int r) {
    if (p < r) {
        int q = Partition(A, p, r);
        QuickSort(A, p, q - 1);
        QuickSort(A, q + 1, r);
    }
}

int n, a[N];
int main() {
    freopen("QuickSort.inp", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    QuickSort(a, 1, n);
    for (int i = 1; i <= n; i ++)
        cout << a[i] << " ";
    cout << endl;
    return 0;
}
