#include <iostream>
#include <cstdio>

using namespace std;
const int oo = 1e9 + 7;

void merge(int A[], int p, int q, int r)  {
    int n1 = q - p + 1,
        n2 = r - q;
    int L[n1 + 1], R[n2 + 1];
    for (int i = 1; i <= n1; i ++)
        L[i] = A[i + p - 1];
    for (int j = 1; j <= n2; j ++)
        R[j] = A[j + q];
    L[n1 + 1] = oo, R[n2 + 1] = oo;
    int i = 1, j = 1;
    for (int k = p; k <= r; k ++) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i ++;
        } else {
            A[k] = R[j];
            j ++;
        }
    }
}
void sort(int A[], int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        sort(A, p, q);
        sort(A, q + 1, r);
        merge(A, p, q, r);
    }
}
int n, a[124];
int main() {
    freopen("MergeSort.inp", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    sort(a, 1, n);
    for (int i = 1; i <= n; i ++)
        cout << a[i] << " ";
    return 0;
}
