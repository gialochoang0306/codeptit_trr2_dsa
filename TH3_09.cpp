#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF));
    for(int i = 1; i <= n; i++){
        dist[i][i] = 0;
    }
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v], w);
    }
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(dist[i][k] < INF && dist[k][j] < INF){
                    dist[i][j] = min(dist[i][j], max(dist[i][k], dist[k][j]));
                }
            }
        }
    }
    
    for(int i = 0; i < q; i++){
        int a, b;
        cin >> a >> b;
        if(dist[a][b] == INF){
            cout << -1 << "\n";
        }
        else{
            cout << dist[a][b] << "\n";
        }
    }
    return 0;
}