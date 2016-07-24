#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <vector>
#include <list>
#include <stack>
using namespace std;

class Graph {
    int V;
    vector<int> *adj;
    void topoSortUtil(int v, bool visited[], stack<int> &st);
public:
    Graph(int V);
    void addEdge(int v, int w);
    void topoSort();
};
Graph::Graph(int V) {
    this->V = V;
    adj = new vector<int>[V];
}
void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
}
void Graph::topoSortUtil(int v, bool visited[], stack<int> &st) {
    visited[v] = true;
    vector<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); i ++)
        if (!visited[*i]) topoSortUtil(*i, visited, st);
    st.push(v);
}
void Graph::topoSort() {
    stack<int> Stack;
    bool *visited = new bool[V];
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < V; i ++)
        if (!visited[i]) topoSortUtil(i, visited, Stack);
    while (!Stack.empty()) {
        cout << Stack.top() << " ";
        Stack.pop();
    }
}

const int N = 1e4 + 5;
int n, m;
bool vis[N];
vector<int> adj[N];
stack<int> topo;

void addEdge(int u, int v) {
    adj[u].push_back(v);
}
void dfs(int u) {
    vis[u] = true;
    for (int v = 0; v < adj[u].size(); v ++) {
        int to = adj[u][v];
        if (!vis[to]) {
            vis[to] = true;
            dfs(to);
        }
    }
    topo.push(u);
}
void topoSort() {
    memset(vis, false, sizeof(vis));
    for (int v = 1; v <= n; v ++)
        if (!vis[v]) dfs(v);
    while (!topo.empty()) {
        cout << topo.top() << " ";
        topo.pop();
    }
}
int main() {
 //   freopen("TopoSort.inp", "r", stdin);
    while (true) {
        cin >> n >> m;
        if (n + m == 0) break;
        //Graph g(n + 1);
        for (int i = 1; i <= m; i ++) {
            int u, v;
            cin >> u >> v;
            addEdge(u, v);
           // g.addEdge(u, v);
        }
        topoSort();
        cout << endl;
    }
//    cout << endl;
//    g.topoSort();
    return 0;
}
