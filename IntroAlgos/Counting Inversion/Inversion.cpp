#include <iostream>
#include <cstdio>

using namespace std;

const int oo = 1e9 + 7;
const int N = 1e5 + 5;

int merge(int A[], int p, int q, int r) {
    int n1 = q - p + 1,
        n2 = r - q;
    int L[n1 + 1], R[n2 + 1];
    for (int i = 1; i <= n1; i ++)
        L[i] = A[p + i - 1];
    for (int j = 1; j <= n2; j ++)
        R[j] = A[q + j];
    L[n1 + 1] = oo, R[n2 + 1] = oo;
    int i = 1, j = 1,
        mInv = 0;
    for (int k = p; k <= r; k ++) {
        if (R[j] < L[i]) {
            mInv += n1 - i + 1;
            A[k] = R[j];
            j ++;
         } else {
            A[k] = L[i];
            i ++;
        }
    }
    return mInv;
}

int countInv(int A[], int p, int r) {
    int inv = 0;
    if (p < r) {
        int q = (p + r) / 2;
        inv += countInv(A, p, q);
        inv += countInv(A, q + 1, r);
        inv += merge(A, p, q, r);
    }
    return inv;
}
int n, a[N];
int main() {
   // freopen("Inversion.inp", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    cout << countInv(a, 1, n) << endl;
    return 0;
}
