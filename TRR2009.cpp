#include<bits/stdc++.h>
using namespace std;

int n, a[105][105], vs[105];
vector<vector<int>> res;
vector<int> tmp;


void dfs(int u){
    vs[u] = 1;
    tmp.push_back(u);

    for(int i = 1; i <= n; i++){
        if(a[u][i] && !vs[i]){
            dfs(i);
        }
    }
}

int main(){

    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 1; i <= n; i++){
        if(!vs[i]){
            tmp.clear();
            dfs(i);
            sort(tmp.begin(), tmp.end());
            res.push_back(tmp);
        }
    }

    cout << res.size() << "\n";
    for(int i = 0; i < res.size(); i++){
        for(int x : res[i]){
            cout << x << " ";
        }
        cout << "\n";
    }

}