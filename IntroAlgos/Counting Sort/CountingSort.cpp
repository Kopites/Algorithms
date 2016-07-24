#include <iostream>
#include <cstdio>

using namespace std;

const int N = 1e5 + 5;

void CountingSort(int A[], int n, int k) {
    int C[N], B[N];
    for (int i = 0; i <= k; i ++)
        C[i] = 0;
    for (int j = 1; j <= n; j ++)
        C[A[j]] = C[A[j]] + 1;
    for (int i = 1; i <= k; i ++)
        C[i] = C[i] + C[i - 1];
    for (int j = n; j >= 1; j --) {
        B[C[A[j]]] = A[j];
        C[A[j]] = C[A[j]] - 1;
    }
    for (int i = 1; i <= n; i ++)
        A[i] = B[i];
}
int n, a[N];
int main() {
    freopen("CountingSort.inp", "r", stdin);
    cin >> n;
    int K = 0;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        K = max(K, a[i]);
    }
    CountingSort(a, n, K);
    for (int i = 1; i <= n; i ++)
        cout << a[i] << " ";
    cout << endl;
    return 0;
}
