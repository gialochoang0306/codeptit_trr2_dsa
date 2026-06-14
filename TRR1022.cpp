#include<bits/stdc++.h>
using namespace std;

int V, E, a[105][105], dm[105], dp[105];

void case1(){
    cin >> V >> E;
    for(int i = 0; i < E; i++){
        int u, v, w;
        cin >> u >> v >> w;

        dp[u]++;
        dm[v]++;
    }

    for(int i = 1; i <= V; i++){
        cout << dm[i] << " " << dp[i] << "\n";
    }
}

struct edge{
    int u, v, w;
    bool operator < (const edge &ot) const{
        if(u < ot.u) return true;
        if(u == ot.u && v < ot.v) return true;
        return false;
    }
};

void case2(){
    cin >> V >> E;
    vector<edge> ed;
    for(int i = 0; i < E; i++){
        int u, v, w;
        cin >> u >> v >> w;
        ed.push_back({u, v, w});
        
    }

    sort(ed.begin(), ed.end());

    for(int i = 1; i <= V; i++){
        for(int j = 1; j <= V; j++){
            if(i != j) a[i][j] = 10000;
        }
    }

    for(int i = 0; i < E; i++){
        a[ed[i].u][ed[i].v] = ed[i].w;
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
    int t;
    cin >> t;
    if(t==1){
        case1();
    }
    else{
        case2();
    }
}