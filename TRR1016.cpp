#include<bits/stdc++.h>
using namespace std;

int V, E;
int dp[105], dm[105];

void case1(){
    cin >> V >> E;
    for(int i = 0; i < E; i++){
        int u,v;
        cin >> u >> v;
        dp[u]++;
        dm[v]++;
    }
    for(int i = 1; i <= V; i++){
        cout << dm[i] << " "<< dp[i] << "\n";
    }
}

void case2(){
    cin >> V >> E;
    vector<vector<int>> ke(V + 5, vector<int>());

    for(int i = 0; i < E; i++){
        int u, v;
        cin >> u >> v;
        ke[u].push_back(v);
    }
    cout << V << "\n";
    for(int i = 1; i <= V; i++){
        cout << ke[i].size() << " ";
        for(int x : ke[i]) cout << x << " ";
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