#include <iostream>
#include <cstdio>

using namespace std;

const int MaxE = 1e5 + 5;
struct QUEUE {
    int Tail, Head;
    int Q[MaxE];
};
void EnQueue(QUEUE& q, int x) {
    q.Q[q.Tail] = x;
    q.Tail = q.Tail % MaxE + 1;

}
int DeQueue(QUEUE& q) {
    int x = q.Q[q.Head];
    q.Head = q.Head % MaxE + 1;
    return x;
}

int main() {
    freopen("", "r", stdin);
    QUEUE Q;
    Q.Head = Q.Tail = 0;
    EnQueue(Q, 1);
    EnQueue(Q, 2);
    EnQueue(Q, -4);
    cout << DeQueue(Q) << endl;
    cout << DeQueue(Q) << endl;
    cout << DeQueue(Q) << endl;
    return 0;
}
