#include<bits/stdc++.h>
using namespace std;

int V;

void case1(){
    cin >> V;
    for(int i = 0; i < V; i++){
        int k, v;
        cin >> k;
        cout << k << " ";
        while(k--){
            cin >> v;
        }
    }
    cout << "\n";
}


int a[105][105];
struct edge
{
    int u, v;
    bool operator < (const edge &ot) const{
        if(u < ot.u) return true;
        if(u == ot.u && v < ot.v) return true;
        return false;
    }
};

void case2(){
    cin >> V;
    vector<edge> ed;

    for(int i = 1; i < V + 1; i++){
        int k, v;
        cin >> k;
        while(k--){
            cin >> v;
            if(i < v){
                ed.push_back({i, v});
            }
        }
    }

    sort(ed.begin(), ed.end());
    int m = ed.size();
    for(int i = 0; i < m; i++){
        int u = ed[i].u, v = ed[i].v;
        a[u][i+1] = 1;
        a[v][i+1] = 1;
    }

    cout << V << " " << m << "\n";
    for(int i = 1; i <= V; i++){
        for(int j = 1; j <= m; j++){
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