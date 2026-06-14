#include <bits/stdc++.h>
using namespace std;

vector<int> adj[10005];
vector<int> radj[10005];
bool vs[10005];
stack<int> st;

void dfs1(int u){
    vs[u] = true;
    for(int v : adj[u]){
        if(!vs[v]){
            dfs1(v);
        }
    }
    st.push(u);
}

void dfs2(int u){
    vs[u] = true;
    for(int v : radj[u]){
        if(!vs[v]){
            dfs2(v);
        }
    }
}

void solve(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        adj[i].clear();
        radj[i].clear();
        vs[i] = false;
    }

    while(!st.empty()) st.pop();

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >>v;
        adj[u].push_back(v);
        radj[v].push_back(u);
    }

    for(int i = 1; i <= n; i++){
        if(!vs[i]){
            dfs1(i);
        }
    }

    for(int i = 1; i <= n; i++){
        vs[i] = false;
    }

    int cnt = 0;
    while(!st.empty()){
        int u = st.top();
        st.pop();

        if(!vs[u]){
            cnt++;
            dfs2(u);
        }
    }
    cout << cnt << "\n";
}

int main() {
    solve();
    return 0;
}