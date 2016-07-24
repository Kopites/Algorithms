#include <iostream>
#include <cstdio>

using namespace std;
const int OO = 1e9 + 7;

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
int Max(int a[]) {
    return (a[1]);
}
int MaxExtract(int a[]) {
    if (Size < 1) {
        cerr << "@underflow" << endl;
        return -OO;
    }
    else {
        int MaxE = a[1];
        a[1] = a[Size];
        -- Size;
        Heapify(a, 1);
        return MaxE;
    }
}
void IncreaseKey(int a[], int i, int key) {
    if (key < a[i]) cerr << "@new key less than current key" << endl;
    else {
        a[i] = key;
        while (i > 1 && a[i] > a[parent(i)]) {
            swap(a[i], a[parent(i)]);
            i = parent(i);
        }
    }
}
void Insert(int a[], int key) {
    ++ Size;
    a[Size] = -OO;
    IncreaseKey(a, Size, key);
}
const int MAXN = 1e5 + 5;
int N, A[MAXN];

int main() {
    freopen("", "r", stdin);

    return 0;
}
