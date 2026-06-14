#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("DT.INP", "r", stdin); freopen("DT.OUT", "w", stdout);
    int t;
    cin >> t;
    int n;
    cin >> n;

    vector<vector<int>> adj(n + 1, vector<int>(n + 1));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> adj[i][j];
        }
    }

    if(t == 1){
        for(int i = 1; i <= n; i++){
            int dm = 0, dp = 0;
            for(int j = 1; j <=n; j++){
                if(adj[j][i] == 1) dm++;
                if(adj[i][j] == 1) dp++;
            }
            cout << dm << " " << dp << "\n";
        }
    }
    else if(t == 2){
        vector<pair<int, int>> e;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(adj[i][j] == 1){
                    e.push_back({i, j});
                }
            }
        }
        int m = e.size();
        cout << n << " " << m << "\n";

        vector<vector<int>> inc(n + 1, vector<int>(m + 1, 0));
        for(int k = 1; k <= m; k++){
            int u = e[k-1].first;
            int v = e[k-1].second;

            inc[u][k] = 1;
            inc[v][k] = -1;
        }

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                cout << inc[i][j] << " ";
            }
            cout << "\n";
        }


    }
    return 0;

}