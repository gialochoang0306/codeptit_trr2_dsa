#include<bits/stdc++.h>
using namespace std;

int V, E, dm[105], dp[105], a[105][105];
struct edge
{
    int u,v;
    bool operator < (const edge &ot) const{
        if(u < ot.u ) return true;
        if(u == ot.u && v < ot.v) return true;
        return false;
    }
};

void case1(){
    cin >> V >> E;
    for(int i = 0; i < E; i++){
        int u, v;
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
    vector<edge> ed;

    for(int i = 0; i < E; i++){
        int u,v;
        cin >> u >> v;
        ed.push_back({u, v});
    }

    sort(ed.begin(), ed.end());
    for(int i = 0; i < E; i++){
        a[ed[i].u][i+1] = 1;
        a[ed[i].v][i+1] = -1;
    }

    cout << V << " " << E << "\n";
    for(int i = 1; i <= V; i++){
        for(int j = 1; j <= E; j++){
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