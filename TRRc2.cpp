#include<bits/stdc++.h>
using namespace std;

struct edge{int u, v, w;};
int p[105], n, m, sum = 0;
vector<edge> e, mst;

int find(int i){
    return p[i] == i ? i : p[i] = find(p[i]);
}


int main(){
    freopen("CK.INP", "r", stdin); freopen("CK.OUT", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        p[i] = i;
    }
    for(int i = 0, u, v, w; i < m; i++){
        cin >> u >> v >> w;
        e.push_back({u, v, w});
    }

    stable_sort(e.begin(), e.end(), [](edge a, edge b) {return a.w < b.w;});
    for(auto x : e){
        int u = find(x.u);
        int v = find(x.v);

        if(u != v){
            p[u] = v;
            sum += x.w;
            mst.push_back(x);
        }
    }

    if(mst.size() == n - 1){
        cout << sum << "\n";
        for(auto x : mst) cout << x.u << " " << x.v << " " << x.w << "\n";
    }
    else{
        cout << 0 << "\n";
    }
}