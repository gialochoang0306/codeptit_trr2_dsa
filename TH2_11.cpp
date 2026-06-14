#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> node(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> node[i];
        node[i]--;
    }

    vector<vector<vector<int>>> adj(n + 1, vector<vector<int>>(3));

    for(int i = 0; i < m; i++){
        int u, v, c;
        cin >> u >> v >> c;
        c--;
        adj[u][c].push_back(v);
    }
    vector<vector<vector<int>>> dist(n + 1, vector<vector<int>>(n + 1, vector<int>(3, -1)));

    queue<tuple<int, int, int>> q;
    q.push({1, 2, 0});
    dist[1][2][0] = 0;

    while(!q.empty()){
        auto [u, v, r] = q.front();
        q.pop();
        int d = dist[u][v][r];
        if(u == v){
            cout << d << "\n";
            return;
        }

        int req1 = (node[v] - r + 3) % 3;
        int req2 = (node[u] - r + 3) % 3;

        for(int nxu : adj[u][req1]){
            for(int nxv : adj[v][req2]){
                int nxr = (r + 1) % 3;

                if(dist[nxu][nxv][nxr] == -1){
                    dist[nxu][nxv][nxr] = d + 1;
                    q.push({nxu, nxv, nxr});
                }
            }
        }
    }
    cout << -1 << "\n";
}

int main() {
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}