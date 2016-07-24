#include <iostream>
#include <cstring>
#include <cassert>
#include <vector>
#include <stack>
#include <cstdio>
#define DEBUG(x) cerr << #x << " = " << x << endl;

using namespace std;

const int N = 1e5 + 5;
int num[N], low[N];
int cnt = 0, SCC = 0;
int n, m;
vector<int> adj[N];
stack<int> st;
bool stackeMember[N], visited[N];

void addEdge(int u, int v) {
    adj[u].push_back(v);
}

void TarjanSCC(int u) {
    num[u] = low[u] = ++ cnt;
    st.push(u);
    stackeMember[u] = true;
    vector<int>::iterator it;
    for (int i = 0; i <  adj[u].size(); i ++) {
        int v = adj[u][i];
        if (num[v] == -1) {
            TarjanSCC(v);
            low[u] = min(low[u], low[v]);

        } else if (stackeMember[v] == true) {
            low[u] = min(low[u], num[v]);
        }
    }
    if (low[u] == num[u]) {
        int v;
        while (u != v) {
            v = st.top();
            cout << v << " ";
            st.pop();
            stackeMember[v] = false;
        }
        ++ SCC;
       cout << endl;
    }
}

void init() {
   // assert(freopen("TarjanSCC.inp", "r", stdin));
    memset(visited, false, sizeof(visited));
    memset(stackeMember, false, sizeof(stackeMember));
    memset(num, -1, sizeof(num));
    memset(low, -1, sizeof(low));
    cin >> n >> m;
    for (int i = 1; i <= m; i ++) {
        int u, v;
        cin >> u >> v;
        addEdge(u, v);
    }
}
void solve() {
    for (int v = 1; v <= n; v ++)
        if (num[v] == -1) TarjanSCC(v);
    cout << SCC << endl;
}
int main() {
    init();
    solve();
    return 0;
}
