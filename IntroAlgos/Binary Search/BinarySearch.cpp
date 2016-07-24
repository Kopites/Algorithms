#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
#define TASK  "TEST"
#define DEBUG(x) cerr << #x << " = " << x << endl;

int n, a[N];
void readInp() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i ++)
    scanf("%d", a + i);
}
void insertionSort(int Len, int A[]) {
  for (int j = 2; j <= Len; j ++) {
    int KEY = A[j];
    int i = j - 1;
    while (i > 0 && A[i] > KEY) {
      A[i + 1] = A[i];
      i --;
    }
    A[i + 1] = KEY;
  }
}
void writeOut(int Len, int A[]) {
  for (int i = 1; i <= Len; i ++)
    printf("%d ", A[i]);
}
void selectionSort(int len, int x[]) {
  for (int i = 1; i < len; i ++) {
    int id = i, smallest = x[id];
    for (int j = i + 1; j <= len; j ++) {
      if (smallest > x[j]) {
        smallest = x[j];
        id = j;
      }
    }
    swap(x[id], x[i]);
  }
}

const int OO = 1e9 + 7;
const int MAX_SIZE = 1e5 + 5;

void merge(int x[], int p, int q, int r) {
  int n1 = q - p + 1,
      n2 = r - q;
  int L[MAX_SIZE], R[MAX_SIZE];
  for (int i = 1; i <= n1; i ++)
    L[i] = x[p + i - 1];
  for (int j = 1; j <= n2; j ++)
    R[j] = x[q + j];
  L[n1 + 1] = OO, R[n2 + 1] = OO;
  int i = 1, j = 1;
  for (int k = p; k <= r; k ++)
    if (L[i] < R[j]) {
      x[k] = L[i];
      ++ i;
    } else {
      x[k] = R[j];
      ++ j;
    }
}
void mergeSort(int x[], int p, int r) {
  if (p < r) {
    int q = (p + r) / 2;
    mergeSort(x, p, q);
    mergeSort(x, q + 1, r);
    merge(x, p, q, r);
  }
}
int binarySearch(int v, int x[], int p, int r) {
  while (p <= r) {
    int q = p + (r - p) / 2;
    if (x[q] == v) {
        return q;
    } else if (x[q] > v) {
      r = q - 1;
    } else {
      p = q + 1;
    }
  }
  return -1;
}
int binarySearch1(int v, int x[], int p, int r) {
  if (p < r) {
    int q = p + (r - p) / 2;
    if (x[q] == v) return q;
    else if (x[q] > v) return binarySearch1(v, x, p, q - 1);
    else return binarySearch1(v, x, q + 1, r);
  }
  return -1;
}
int main() {
  #define LOCAL
  #ifdef LOCAL
    assert(freopen(TASK".INP", "r", stdin));
    //assert(freopen(TASK".OUT", "w", stdout));
  #endif // LOCAL
  readInp();
  //selectionSort(n, a);
  //insertionSort(n, a);
  mergeSort(a, 1, n);
  int v = -36;
  DEBUG(binarySearch(v, a, 1, n));
  DEBUG(binarySearch1(v, a, 1, n));
  writeOut(n, a);
  return 0;
}
