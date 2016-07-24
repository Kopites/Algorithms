#include <iostream>
#include "queue"
#include <vector>
#include <cstring>
#include <cassert>
#include <cstdio>
#define DEBUG(x) cerr << #x << " = " << x << endl;

using namespace std;
const int M = 1e3 + 5;
const int N = 1e5 + 5;
int n, m, mtk[M][M];
vector<int> adj[N];

bool vis[N];

void init(int edge) {
    for (int i = 1; i <= edge; i ++)
        for (int j = 1; j <= edge; j ++)
            mtk[i][j] = 0;
}
int trace[N];
void bfs(int s) {
    queue<int> qu; qu.push(s);
    vis[s] = true;
    while (!qu.empty()) {
        int u = qu.front(); qu.pop();
        cout << u << "\n";
        for (int v = 0; v < adj[u].size(); v ++) {
            int to = adj[u][v];
            if (!vis[to]) {
                vis[to] = true;
                qu.push(to);
            }
        }
    }
}

void dfs(int u) {
    vis[u] = true;
    cout << u << endl;
    for (int v = 0; v < adj[u].size(); v ++) {
        int to = adj[u][v];
        if (!vis[to]) {
            vis[to] = true;
            dfs(to);
        }
    }
}
int main() {
    assert(freopen("GraphRepresent.inp", "r", stdin));
    memset(vis, false, sizeof(vis));
    cin >> n >> m;
    init(n);
    for (int i = 1; i <= m; i ++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v); adj[v].push_back(u);
        mtk[u][v] = mtk[v][u] = 1;
    }
    bfs(1);
    cout << " _____ \n";
    memset(vis, false, sizeof(vis));
    dfs(1);
    return 0;
    for (int i = 1; i <= n; i ++) {
        cout << i << ": ";
        for (int j = 0; j < adj[i].size(); j ++)
            cout << adj[i][j] << " ";
        cout << endl;
    }
    return 0;
    cout << " ------------------------ " << endl;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            if (mtk[i][j]) cout << i << " " << j << endl;

    return 0;
}
