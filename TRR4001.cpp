#include<bits/stdc++.h>
using namespace std;

int a[105][105], vs[105], k, V;
struct edge{
    int u, v;
    edge(int x, int y){
        if(x < y){
            u = x;
            v = y;
        }
        else{
            u = y;
            v = x;
        }
    }
};

vector<edge> ed;
void dfs(int u){
    vs[u] = 1;
    for(int i = 1; i <= V; i++){
        if(!vs[i] && a[u][i]){
            ed.push_back({u, i});
            vs[i] = 1;
            dfs(i);
        }
    }
}

void bfs(int u){
    queue<int> q;
    q.push(u);
    vs[u] = 1;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int i = 1; i <= V; i++){
            if(!vs[i] && a[v][i]){
                vs[i] = 1;
                ed.push_back({v, i});
                q.push(i);
            }
        }
    }
}

void case1(){
    int s;
    cin >>V >> s;
    for(int i = 1; i <= V; i++){
        for(int j = 1; j <= V; j++){
            cin >> a[i][j];
        }
    }

    dfs(s);

    if(ed.size() == V - 1){
        cout << ed.size() << "\n";
        for(auto x : ed){
            cout << x.u << " " << x.v << "\n";
        }
    }
    else{
        cout << 0 << "\n";
    }

}
void case2(){
    int s;
    cin >>V >> s;
    for(int i = 1; i <= V; i++){
        for(int j = 1; j <= V; j++){
            cin >> a[i][j];
        }
    }

    bfs(s);

    if(ed.size() == V - 1){
        cout << ed.size() << "\n";
        for(auto x : ed){
            cout << x.u << " " << x.v << "\n";
        }
    }
    else{
        cout << 0 << "\n";
    }
}

int main(){

    freopen("CK.INP", "r", stdin);
    freopen("CK.OUT", "w", stdout);
    int t;
    
    cin >> t;
    if(t==1){
        case1();
    }
    else{
        case2();
    }
}