#include<bits/stdc++.h>
using namespace std;

int V;
int cnt[105];
void case1(){
    cin >> V;
    for(int i = 0; i < V; i++){
        int k, v;
        cin >> k;
        cout << k << " ";
        while(k--){
            cin >> v;
        }
    }
    cout << "\n";
}


 struct edge
 {
    int u, v;
    bool operator < (const edge &ot) const {
        if(u < ot.u) return true;
        if(u == ot.u && v < ot.v) return true;
        return false;
    }
 };
 


void case2(){
    cin >> V;
    vector<edge> ed;
    for(int i = 1; i <= V; i++){
        int k, v;
        cin >> k;
        while(k--){
            cin >> v;
            if(i < v){
                ed.push_back({i, v});
            }
        }
    }
    sort(ed.begin(), ed.end());
    cout << V << " " <<  ed.size() << "\n";
    for(int i = 0; i < ed.size(); i++){
        cout << ed[i].u << " " << ed[i].v << "\n";
    }
}

int main(){
    //freopen("DT.INP", "r", stdin);
    //freopen("DT.OUT", "w", stdout);
    int t;
    cin >> t;
    if(t==1){
        case1();
    }
    else{
        case2();
    }
}