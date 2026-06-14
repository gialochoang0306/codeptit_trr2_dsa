#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int a[1005][1005];
int dp[1005][1005];

void solve(){
    int m, n;
    cin >> m >> n;
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
            dp[i][j] = INF;
        }
    }
    dp[1][1] = 0;

    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(dp[i][j] == INF) continue;

            int step = a[i][j];
            if(i + step <= m){
                dp[i + step][j] = min(dp[i + step][j], dp[i][j] + 1);
            }
            if(j + step <= n){
                dp[i][j + step] = min(dp[i][j + step], dp[i][j] + 1);
            }
        }
    }
    if(dp[m][n] == INF){
        cout << -1 << "\n";
    }
    else{
        cout << dp[m][n] << "\n";
    }
}

int main() {
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}