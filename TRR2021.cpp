#include<bits/stdc++.h>
using namespace std;

int V, a[105][105], vs[105];
vector<int> res;

void dfs(int u){
    vs[u] = 1;
    for(int i = 1; i <= V; i++){
        if(vs[i] == 0 && a[u][i]){
            dfs(i);
        }
    }
}

int tplt(int skip){
    memset(vs, 0, sizeof(vs));

    vs[skip] = 1;
    int cnt = 0;
    for(int i = 1; i <= V; i++){
        if(!vs[i]){
            cnt++;
            dfs(i);
        }
    }
    return cnt;
}

int main(){
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);
    cin >> V;
    for(int i = 1; i <= V; i++){
        for(int j = 1; j <= V; j++){
            cin >> a[i][j];
        }
    }

    int org = tplt(0);
    for(int i = 1; i <= V; i++){
        int now = tplt(i);
        if(now > org) res.push_back(i);
    }

    cout << res.size() << "\n";
    for(int x : res){
        cout << x << " ";
    }


}