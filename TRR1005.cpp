#include<bits/stdc++.h>
using namespace std;

int V, E;
int cnt[105];


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

void case2(){
    cin >> V >> E;
    vector<vector<int>> a(V + 1, vector<int>());
    cout << V << "\n";
    for(int i = 0; i < E; i++){
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    for(int i = 1; i <= V; i++){
        cout << a[i].size() << " ";
        for(int x : a[i]){
            cout << x << " ";
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