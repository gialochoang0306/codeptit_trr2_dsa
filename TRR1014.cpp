#include<bits/stdc++.h>
using namespace std;

int V, a[105][105], dm[105], dp[105];
int b[105][505];
void case1(){
    cin >> V;
    for(int i = 1; i <= V; i++){
        for(int j = 1; j <= V; j++){
            cin >> a[i][j];
        }
    }

    for(int i = 1; i <= V; i++){
        for(int j = 1; j <= V; j++){
            if(a[j][i]) dm[i]++; 
        }
    }

    for(int i = 1; i <= V; i++){
        for(int j = 1; j <= V; j++){
            if(a[i][j]) dp[i]++;
        }
    }

    for(int i = 1; i <= V; i++){
        cout << dm[i] << " " << dp[i] << "\n";
    }
}


struct edge{
    int u,v;
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
            if(a[i][j]) ed.push_back({i, j});
        }
    }
    sort(ed.begin(), ed.end());
    int E = ed.size();

    for(int i = 0; i < E; i++){
        b[ed[i].u][i+1] = 1;
        b[ed[i].v][i+1] = -1;
    }
    cout << V << " " <<  E << "\n";
    for(int i = 1; i <= V; i++){
        for(int j = 1; j <= E; j++){
            cout << b[i][j] << " ";
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