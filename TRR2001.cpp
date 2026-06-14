#include <bits/stdc++.h>
using namespace std;

int a[105][105], V, s, t, vs[105], pr[105];


bool dfs(int s, int t){
    vs[s] = 1;
    if(s == t) return true;
    for(int i=1; i<=V; i++){
        if(a[s][i] && !vs[i]){
            pr[i] = s;
            if(dfs(i, t)) return true;
        }
    }
    return false;
}

vector<int> in(int s, int t){
    vector<int> tmp;
    while(t != -1){
        tmp.push_back(t);
        t = pr[t];
    }
    reverse(tmp.begin(), tmp.end()); //algorithm
    return tmp;
}

int main(){
    freopen("TK.INP","r",stdin);
    freopen("TK.OUT","w",stdout);
    int T; cin >> T;
    cin >> V >> s >> t;
    memset(a, 0, sizeof(a));
    memset(vs, 0, sizeof(vs));
    memset(pr, -1, sizeof(pr));
    for(int i=1; i<=V; i++){
        for(int j=1; j<=V; j++){
            cin >> a[i][j];
        }
    }

    if(T == 1){
        int cnt = 0;
        for(int i = 1; i <= V; i++){
            if(i != s && i != t && a[s][i] == 1 && a[i][t] == 1) cnt++;
        }
        cout << cnt << "\n";
    }
    else if(T == 2){
        if(dfs(s, t)){
            vector<int> res = in(s, t);
            for(int v : res) cout << v << " ";
            cout << "\n";
        } else {
            cout << "0\n"; 
        }
    }
    return 0;
}