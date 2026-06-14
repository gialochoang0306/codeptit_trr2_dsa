#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;

struct edge{int u, v, w;};

void solve(){
    freopen("BN.INP", "r", stdin); freopen("BN.OUT", "w", stdout);
    int n, s, t;
    cin >> n >> s >> t;
    vector<edge> e;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int w;
            cin >> w;
            if(i != j){
                e.push_back({i, j, w});
            }
        }
    }

    vector<int> dist(n + 1, INF);
    vector<int> par(n + 1, 0);
    dist[s] = 0;
    for(int i = 1; i < n; i++){
        for(const auto x : e){
            if(dist[x.u] != INF && dist[x.v] > dist[x.u] + x.w){
                dist[x.v] = dist[x.u] + x.w;
                par[x.v] = x.u;
            }
        }
    }
    bool neg = false;

    for(const auto& x : e){
        if(dist[x.u] != INF && dist[x.v] > dist[x.u] + x.w){
            neg = true;
            break;
        }
    }
    if(neg){
        cout << -1 << "\n";
    }
    else if(dist[t] == INF){
        cout << 0 << "\n";
    }
    else{
        cout << dist[t] << "\n";
        vector<int> p;
        for(int v = t; v != 0; v= par[v]){
            p.push_back(v);
        }
        reverse(p.begin(), p.end());
        for(int i = 0; i < p.size(); i++){
            cout << p[i] << ' ';
        }
        cout << "\n";

    }

}

int main(){
    solve();
    return 0;
}