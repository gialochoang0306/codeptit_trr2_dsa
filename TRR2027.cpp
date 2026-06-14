#include<bits/stdc++.h>
using namespace std;

int V, a[105][105], vs[105];
vector<pair<int, int>> res;

void bfs(int u){
    vs[u] = 1;
    queue<int> q;
    q.push(u);
    while(!q.empty()){
        int v = q.front();
        q.pop();


        for(int i = 1; i <= V; i++){
            if(!vs[i] && a[v][i]){
                q.push(i);
                vs[i] = 1;
            }
        }
    }
}


int tplt(){
    memset(vs, 0, sizeof(vs));
    int cnt = 0;
    for(int i = 1; i <= V; i++){
        if(!vs[i]){
            cnt++;
            bfs(i);
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

    int org = tplt();

    for(int i = 1; i <= V; i++){
        for(int j = i + 1; j <= V; j++){
            if(a[i][j]){
                a[i][j] = a[j][i] = 0;

                int now = tplt();
                if(now > org){
                    res.push_back({i, j});
                }
                a[i][j] = a[j][i] = 1;
            }
        }
    }

    cout << res.size() << "\n";
    for(auto x : res){
        cout << x.first << " " << x.second << "\n";
    }


}