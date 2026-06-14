#include<bits/stdc++.h>
using namespace std;

int V, E;
int pr[105];

struct edge{
    int u, v, w;

    bool operator <(const edge &ot) const{
        if(w != ot.w) return w < ot.w;
        if(u != ot.u) return u < ot.u;
        return v < ot.v;
    }
};

int find(int u){
    if(pr[u] == u){
        return u;
    }
    else{
        pr[u] = find(pr[u]);
        return pr[u];
    }
}

bool uni(int u, int v){
    int pu = find(u), pv = find(v);
    if(pu == pv) return false;
    pr[pu] = pv;
    return true;
}


vector<edge> mst;
vector<edge> ed; 


int main(){
    freopen("CK.INP", "r", stdin);
    freopen("CK.OUT", "w", stdout);
    cin >> V >> E;

    for(int i = 0; i < E; i++){
        int u, v, w;
        cin >> u >> v >> w;
        ed.push_back({u, v, w});
    }

    for(int i = 1; i <= V; i++){
        pr[i] = i;
    }
    sort(ed.begin(), ed.end());
    int val = 0;
    for(int i = 0; i < E; i++){
        if(uni(ed[i].u, ed[i].v)){
            mst.push_back(ed[i]);
            val += ed[i].w;
        }
    }

    if(mst.size() == V - 1){
        cout << val << "\n";
        for(auto e : mst){
            cout << e.u << " " << e.v << " " << e.w << "\n";
        }
    }

}