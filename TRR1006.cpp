#include<bits/stdc++.h>
using namespace std;

int V, E;
int cnt[105];
int a[105][105], b[105][105];

void case1(){
    cin >> V >> E;
    for(int i = 0; i < 2*E; i++){
        int tmp;
        cin >> tmp;
        cnt[tmp]++;
    }
    for(int i = 1; i <= V; i++){
        cout << cnt[i] << " ";
    }
    cout << "\n";
}

struct edge{
    int u, v;
    bool operator < (const edge &ot){
        if(u < ot.u) return true;
        if(u == ot.u && v < ot.v) return true;
        return false;
    }
};

vector<edge> ed;
void case2(){
    cin >> V >> E;
    for(int i=0; i<E; i++){
        int x, y; cin >> x >> y;
        a[x][y] = 1;
        a[y][x] = 1;
    }
    for (int i = 1; i <= V; i++) {
        for (int j = i + 1; j <= V; j++) {
            if (a[i][j] == 1) {
                ed.push_back({i, j});
            }
        }
    }
    sort(ed.begin(), ed.end());
    int m = E;
    for(int k=0; k<m; k++){
        int u = ed[k].u;
        int v = ed[k].v;
        b[u][k+1] = 1;
        b[v][k+1] = 1;
    }
    cout << V << " " << m << "\n";
    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= m; j++) {
            cout << b[i][j] << " ";
        }
        cout << "\n";
    }
}

int main(){
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
    int t;
    cin >> t;
    if(t==1){
        case1();
    }
    else{
        case2();
    }
}