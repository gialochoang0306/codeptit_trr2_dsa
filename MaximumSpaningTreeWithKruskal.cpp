#include<bits/stdc++.h>
using namespace std;

int V, vs[105], a[105][105], pr[105];

struct edge{
    int u, v, w;

    // ta se sap xep vector edge giam dan => chon canh dai nhat truoc
    bool operator < (const edge &ot) const {
        if(w != ot.w) return w > ot.w;
        if(u != ot.u) return u > ot.u;
        return v > ot.v;

    }
};

int find(int u){
    if(pr[u] == u){
        return pr[u];
    }
    else{
        pr[u] = find(pr[u]);
        return pr[u];
    }
}

bool uni(int u, int v){
    int pu = find(u);
    int pv = find(v);

    if(pu == pv) return false;
    pr[pu] = pv;
    return true;
}


vector<edge> res;
vector<edge> ed;
int main(){
    cin >> V;
    for(int i =1; i <= V; i++){
        pr[i] = i;
    }
    for(int i = 1; i <= V; i++){
        for(int j = 1; j <= V; j++){
            cin >> a[i][j];
            if(a[i][j] > 0 && a[i][j] <= 50){
                if(i < j){
                    ed.push_back({i, j, a[i][j]});
                }
            }
        }
    }

    sort(ed.begin(), ed.end());
    int val = 0;
    for(auto e : ed){
        if(uni(e.u, e.v)){
            res.push_back(e);
            val += e.w;
        }
    }

    if(res.size() != V - 1) cout << 0;
    else{
        cout << val << "\n";
        for(auto e : res){
            cout << e.u << " " << e.v << " " << e.w << "\n";
        }
    }
}