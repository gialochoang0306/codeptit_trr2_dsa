#include <bits/stdc++.h>
using namespace std;

void solve(){
    int V, E, u, v;
    cin >> V >> E >> u >> v;
    vector<vector<int>> adj(V + 1);

    for(int i = 0; i < E; i++){
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    
    vector<bool> vs(V + 1, false);
    vector<int> trace(V + 1, 0);
    queue<int> q;

    q.push(u);
    vs[u] = true;

    while(!q.empty()){
        int curr = q.front();
        q.pop();

        if(curr == v){
            break;
        }

        for(int nxt : adj[curr]){
            if(!vs[nxt]){
                vs[nxt] = true;
                trace[nxt] = curr;
                q.push(nxt);
            }
        }
    }
    if(!vs[v]){
        cout << -1 << "\n";
    }
    else{
        vector<int> p;
        int curr = v;
        while(curr != u){
            p.push_back(curr);
            curr = trace[curr];
        }
        p.push_back(u);
        reverse(p.begin(), p.end());

        for(int i = 0; i < p.size(); i++){
            cout << p[i] << (i == p.size() - 1 ? "" : " ");
        }
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}