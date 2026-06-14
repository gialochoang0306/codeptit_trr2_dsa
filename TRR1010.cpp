#include<bits/stdc++.h>
using namespace std;
const int inf  = 10000;
int V, a[105][105];
int cnt[105];


void case1(){
    memset(cnt, 0, sizeof(cnt));
    cin >> V;
    for(int i = 1; i <= V; i++){
        for(int j = 1; j <= V; j++){
            cin >> a[i][j];
            if(a[i][j] > 0 && a[i][j] <= 50){
                cnt[i]++;
            }
        }
    }
    for(int i = 1; i <= V; i++){
        cout << cnt[i] << " ";
    }
    cout << "\n";
}

struct edge{
    int u, v, w;
    bool operator <(const edge &ot) const{
        if(u < ot.u) return true;
        if(u == ot.u && v < ot.v) return true;
        return false;
    }
};


void case2(){
    memset(a, 0, sizeof(a));
    cin >> V;
    vector<edge> ed;
    
    // Bước 1: Đọc TRỌN VẸN ma trận V x V
    for(int i = 1; i <= V; i++){
        for(int j = 1; j <= V; j++){
            cin >> a[i][j];
        }
    }
    
    // Bước 2: Duyệt nửa trên ma trận để tìm cạnh
    for(int i = 1; i <= V; i++){
        for(int j = i + 1; j <= V; j++){
            if(a[i][j] > 0 && a[i][j] <= 50){ // Sửa lại thành <= 50
                ed.push_back({i, j, a[i][j]});
            }
        }
    }
    
    sort(ed.begin(), ed.end());
    cout << V << " " << ed.size() << "\n";
    for(int i = 0; i < ed.size(); i++){
        cout << ed[i].u << " " <<  ed[i].v << " " << ed[i].w << "\n";
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