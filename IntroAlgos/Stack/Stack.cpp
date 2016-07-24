#include <iostream>
#include <cstdio>

using namespace std;
const int MaxE = 1e5 + 5;

int top;
int Stack[MaxE];

void Init() {
    top = 0;
}
bool Empty(int st[], int top) {
    return (top == 0);
}
void Push(int st[], int &top, int E) {
    st[++ top] = E;
}
int Pop(int st[], int &top) {
    -- top;
    return st[top + 1];
}
int main() {
    freopen("", "r", stdin);
    Init();
    Push(Stack, top, 1);
    Push(Stack, top, 19);
    Push(Stack, top, 0);
    Push(Stack, top, -34);
    while (!Empty(Stack, top)) {
        cout << Pop(Stack, top) << endl;
    }
    return 0;
}

