#include <bits/stdc++.h>
using namespace std;

int n, m, e;
vector<vector<int>> adj;
vector<bool> vs;
void dfs(int u){
    vs[u] = true;

    cout << u << " ";
    for(int v : adj[u]){
        if(!vs[v]){
            dfs(v);
        }
    }
}

void solve(){
    cin >> n >> m >> e;
    adj.assign(n + 1, vector<int>());
    vs.assign(n + 1, false);
    int u, v;
    for(int i = 0; i < m; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(e);
    cout << "\n";


}

int main() {
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}