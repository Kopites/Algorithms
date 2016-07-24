#include <iostream>
#include <cstdio>

using namespace std;

const int N = 1e5 + 5;

int n, a[N];

void InsertSort(int len, int a[]) {
    for (int i = 2; i <= len; i ++) {
        int key = a[i];
        int j = i - 1;
        while (j > 0 && a[j] > key) {
            a[j + 1] = a[j];
            j --;
        }
        a[j + 1] = key;
    }
}
int main() {
    freopen("InsertSort.inp", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    InsertSort(n, a);
    for (int i = 1; i <= n; i ++)
        cout << a[i] << " ";
    cout << endl;
    return 0;
}
