#include<bits/stdc++.h>
using namespace std;

int V, E;
int a[105][105];
int cnt[105];
void case1(){
    cin >> V >> E;
    for(int i = 0; i < E; i++){
        int u, v, w;
        cin >> u >> v >> w;
        cnt[u]++;
        cnt[v]++;
    }

    for(int i = 1; i <= V; i++){
        cout << cnt[i] << " ";
    }
    cout << "\n";
}

void case2(){
    cin >> V >> E;
    for(int i = 0; i < E; i++){
        int u, v, w;
        cin >> u >> v >> w;
        a[u][v] = w;
        a[v][u] = w;
    }
    cout << V << "\n";
    for(int i = 1; i <= V; i++){
        for(int j = 1; j <= V; j++){
            if(i != j && a[i][j] == 0){
                a[i][j] = 10000;
            }
        }
    }

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