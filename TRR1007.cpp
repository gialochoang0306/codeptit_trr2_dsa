#include<bits/stdc++.h>
using namespace std;

int cnt[105], a[105][105];
int V, E;


void case1(){
    cin >> V;
    vector<vector<int>> ke(V + 5, vector<int>());
    for(int i = 1; i <= V; i++){
        int k, v;
        cin >> k;
        while(k--){
            cin >> v;
            ke[i].push_back(v);
        }
    }
    for(int i=1; i<=V; i++){
        if(1){
            cout << ke[i].size() << " ";
        }
    }
    cout << "\n";
}

void case2(){
    cin >> V;
    for(int i = 1; i <= V; i++){
        int k, v;
        cin >> k;
        while(k--){
            cin >> v;
            a[i][v] = a[v][i] = 1;
        }
    }

    cout << V << "\n";
    for(int i = 1; i <= V; i++){
        for(int j = 1; j <= V; j++){
            cout << a[i][j] << " ";
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