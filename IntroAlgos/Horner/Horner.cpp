#include <iostream>
#include <cstdio>

using namespace std;

const int N = 1e4 + 5;
int Horner(int a[], int n, int x) {
    int y = 0;
    for (int i = n; i >= 0; i --)
        y = a[i] + x * y;
    return y;
}

int n, x, a[N];
int main() {
    freopen("Horner.inp", "r", stdin);
    cin >> n >> x;
    for (int i = 0; i <= n; i ++)
        cin >> a[i];
    cout << Horner(a, n, x) << endl;
    return 0;
}
