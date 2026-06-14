#include <bits/stdc++.h>
using namespace std;
vector<int> adj[105];
bool vs[105];

int exn;

void dfs(int u){
    vs[u] = true;
    for(int v : adj[u]){
        if(!vs[v] && v != exn){
            dfs(v);
        }
    }
}


void solve(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        adj[i].clear();
        vs[i] = false;
    }

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int intc = 0;
    for(int i = 1; i <= n; i++){
        if(!vs[i]){
            intc++;
            dfs(i);
        }
    }
    int mxc = intc;
    int res = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++) vs[j] = false;
        vs[i] = true;
        int currc = 0;
        for(int j = 1; j <= n; j++){
            if(!vs[j]){
                currc++;
                dfs(j);
            }
        }
        if(currc > mxc){
            mxc = currc;
            res = i;
        }
    }
    cout << res << "\n";
}

int main() {
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}