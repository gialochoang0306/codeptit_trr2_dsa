#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, w;
    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

int parent[105];

void make_set(int v) {
    parent[v] = v;
}

int find_set(int v) {
    if (v == parent[v]) return v;
    int p = find_set(parent[v]);
    parent[v] = p;
    return p;
}

bool union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        parent[b] = a;
        return true;
    }
    return false;
}

void solve() {
    int V, E;
    cin >> V >> E;
    
    vector<Edge> edges(E);
    for (int i = 0; i < E; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }
    
    sort(edges.begin(), edges.end());
    
    for (int i = 1; i <= V; ++i) {
        make_set(i);
    }
    
    long long mst_weight = 0;
    int edges_used = 0;
    
    for (const auto& edge : edges) {
        if (union_sets(edge.u, edge.v)) {
            mst_weight += edge.w;
            edges_used++;
            if (edges_used == V - 1) {
                break;
            }
        }
    }
    
    cout << mst_weight << "\n";
}

int main() {
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}