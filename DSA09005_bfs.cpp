#include <bits/stdc++.h>
using namespace std;

int n, m, e;
vector<vector<int>> adj;
vector<bool> vs;
void bfs(int start){
    queue<int> q;
    q.push(start);
    vs[start] = true;

    while(!q.empty()){
        int u = q.front();
        q.pop();

        cout << u << " ";

        for(int v : adj[u]){
            if(!vs[v]){
                vs[v] = true;
                q.push(v);
            }
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

    bfs(e);
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