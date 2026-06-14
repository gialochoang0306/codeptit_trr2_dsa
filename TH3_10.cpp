#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;


int main() {
    int n, m; 
    cin >> n >> m;
    vector<vector<pair<int, long long>>> adj(n + 1);    
    for(int i = 0; i < m ; i++){
        int u, v;
        long long c;
        cin >> u >> v >> c;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});

    }
    vector<long long> dist(n + 1, INF);
    vector<long long> cnt(n + 1, 0);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    dist[1] = 0;
    cnt[1] = 1;
    pq.push({0, 1});
    while(!pq.empty()){
        long long d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if(d > dist[u]) continue;

        for(auto e : adj[u]){
            int v = e.first;
            long long w = e.second;

            if(dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                cnt[v] = cnt[u];
                pq.push({dist[v], v});
            }
            else if(dist[u] + w == dist[v]){
                cnt[v] += cnt[u];
            }
        }
    }
    cout << dist[n] << ' ' <<  cnt[n];
    return 0;
}