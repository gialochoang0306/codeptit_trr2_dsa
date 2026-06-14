#include<bits/stdc++.h>
using namespace std;


using namespace std;

void solve() {
    int V, E;
    cin >> V >> E;

    vector<vector<int>> adj(V + 1);

    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= V; ++i) {

        sort(adj[i].begin(), adj[i].end());
        
        cout << i << ": ";
        for (int v : adj[i]) {
            cout << v << " ";
        }
        cout << "\n";
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}