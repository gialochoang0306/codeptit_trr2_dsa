#include <bits/stdc++.h>
using namespace std;

void solve(int mode){
    int n;
    cin >> n;
    vector<vector<int>> adj(n, vector<int>());

    int tmp;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> tmp;
            if(tmp == 1){
                adj[i].push_back(j);
            }
        }
    }

    if(mode == 1){
        for(vector<int> &x : adj){
            cout << x.size() << " ";
        }
    }
    else if(mode == 2){
        int cnt = 0;
        for(vector<int> &x : adj){
            cnt += x.size();
        }
        cout << n << " " << cnt / 2 << "\n";

        vector<pair<int, int>> edge;

        for(int i = 0; i < n; i++){
            for(int j : adj[i]){
                if(i < j){
                    edge.push_back({i, j});
                }
            }
        }
        int m = edge.size();
        vector<vector<int>> incm(n, vector<int>(m, 0));

        for(int e = 0; e < m; e++){
            int u = edge[e].first;
            int v = edge[e].second;
            incm[u][e] = 1;
            incm[v][e] = 1;
        }

        for(int i = 0; i < n; i++){
            for(int e = 0; e < m; e++){
                cout << incm[i][e] << " ";
            }
            cout << "\n";
        }

    }
}

int main() {
    freopen("DT.INP", "r", stdin);freopen("DT.OUT", "w", stdout);
    int t;
    cin >> t;
    solve(t);
    return 0;
}