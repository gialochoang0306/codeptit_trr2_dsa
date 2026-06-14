#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MAXN = 505;
int C[MAXN][MAXN];
int F[MAXN][MAXN];

int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> C[i][j];
            if(i == j){
                C[i][j] = INF;
            }
        }
    }    

    for(int k = 0; k <= n; k++){
        for(int v = 0; v <= n; v++){
            F[k][v] = INF;
        }
    }

    for(int v = 1; v <= n; v++){
        F[0][v] = 0;
    }

    for(int k = 1; k <= n; k++){
        for(int u = 1; u <= n; u++){
            if(F[k - 1][u] == INF) continue;
            for(int v = 1; v <= n; v++){
                if(u != v && F[k - 1][u] + C[u][v] < F[k][v]){
                    F[k][v] = F[k - 1][u] + C[u][v];
                }
            }
        }
    }

    long long tu = INF, mau = 1;
    for(int v = 1; v <= n; v++){
        if(F[n][v] == INF){
            continue;
        }

        long long maxt = -INF, maxm = 1;
        for(int k = 0; k < n; k++){
            if(F[k][v] != INF){
                long long curt = F[n][v] - F[k][v];
                long long curm = n - k;

                if(maxt == -INF || curt * maxm > maxt * curm){
                    maxt = curt;
                    maxm = curm;
                }
            }
        }
        if(tu == INF || maxt * mau < tu * maxm){
            tu = maxt;
            mau = maxm;
        }

        
        
    }
    long long g = __gcd(mau, tu);
    cout << tu / g << "/" << mau / g;
    return 0;
}