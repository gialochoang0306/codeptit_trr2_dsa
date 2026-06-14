#include<bits/stdc++.h>
using namespace std;

int V, a[105][105], dm[105], dp[105];

void case1(){
    cin >> V;
    for(int i = 1; i <= V; i++){
        for(int j = 1; j <= V; j++){
            cin >> a[i][j];
        }
    }

    for(int i = 1; i <= V; i++){
        for(int j = 1; j <= V; j++){
            if(a[j][i] != 0 && a[j][i] != 10000) dm[i]++;
        }
    }

    for(int i = 1; i <= V; i++){
        for(int j = 1; j <= V; j++){
            if(a[i][j] != 0 && a[i][j] != 10000) dp[i]++;
        }
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
    cin >> V;
    for(int i = 1; i <= V; i++){
        for(int j = 1; j <= V; j++){
            cin >> a[i][j];
        }
    }
    vector<edge> ed;
    for(int i = 1; i <= V; i++){
        for(int j = 1; j <= V; j++){
            if(a[i][j]!=0 && a[i][j] != 10000){
                ed.push_back({i, j, a[i][j]});
            }
        }
    }

    sort(ed.begin(), ed.end());
    int E = ed.size();

    cout << V << " " << E << "\n";
    for(int i = 0; i < E; i++){
        cout << ed[i].u << " " << ed[i].v << " " << ed[i].w << "\n";
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