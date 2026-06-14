#include<bits/stdc++.h>
using namespace std;
int V, E, a[105][105];
int dm[105], dp[105];

struct edge{
    int u, v;
};

void case1(){
    cin >> V >> E;
    for(int i = 0; i < E; i++){
        int u,v;
        cin >> u >> v;
        dp[u]++;
        dm[v]++;
    }
    for(int i = 1; i <= V; i++){
        cout << dm[i] << " " << dp[i] << "\n";
    }
}


void case2(){
    cin >> V >> E;
    for(int i = 0; i < E; i++){
        int u, v;
        cin >> u >> v;
        a[u][v] = 1;
    }
    cout << V << "\n";

    for(int i = 1; i <= V; i++){
        for(int j = 1; j <= V; j++){
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
}
int main(){
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
    int t;
    cin >> t;
    if(t==1){
        case1();
    }
    else{
        case2();
    }
}