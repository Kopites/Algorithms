#include <iostream>
#include <cstdio>

using namespace std;
int Size;

int parent(int i) {
    return (i / 2);
}
int left(int i) {
    return (2 * i);
}
int right(int i) {
    return (2 * i + 1);
}
void Heapify(int a[], int i) {
    int L = left(i), R = right(i);
    int largest = i;
    if (L <= Size && a[L] > a[i]) {
        largest = L;
    }
    if (R <= Size && a[R] > a[largest]) {
        largest = R;
    }
    if (largest != i) {
        swap(a[i], a[largest]);
        Heapify(a, largest);
    }
}
void BuildHeap(int a[], int n) {
    Size = n;
    for (int i = Size / 2; i >= 1; i --) {
        Heapify(a, i);
    }
}
void HeapSort(int a[], int n) {
    BuildHeap(a, n);
    for (int i = n; i >= 2; i --) {
        swap(a[1], a[i]);
        -- Size;
        Heapify(a, 1);
    }
}
const int MAXN = 1e5 + 5;
int N, A[MAXN];

int main() {
    freopen("HeapSort.inp", "r", stdin);
    cin >> N;
    for (int i = 1; i <= N; i ++)
        cin >> A[i];
    HeapSort(A, N);
    for (int i = 1; i <= N; i ++)
        cout << A[i] << " ";
    return 0;
}
