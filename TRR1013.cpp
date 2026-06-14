#include<bits/stdc++.h>
using namespace std;

int V;
int a[105][105];
int dm[105], dp[105];
void case1(){
    cin >> V;
    for(int i = 1; i <= V; i++){
        for(int j = 1; j <= V; j++){
            cin >> a[i][j];
        }
    }

    for(int i = 1; i <= V; i++){
        for(int j = 1; j <= V; j++){
            if(a[j][i]) dm[i]++;
        }
    }
    for(int i = 1; i <= V; i++){
        for(int j = 1; j <= V; j++){
            if(a[i][j]) dp[i]++;
        }
    }

    for(int i = 1; i <= V; i++){
        cout << dm[i] << " " << dp[i] << "\n";
    }
}

void case2(){
    cin >> V;
    for(int i = 1; i <= V; i++){
        for(int j = 1; j <= V; j++){
            cin >> a[i][j];
        }
    }

    vector<vector<int>> ke(V + 5, vector<int>());

    for(int i = 1; i <= V; i++){
        for(int j = 1; j <= V; j++){
            if(a[i][j]) ke[i].push_back(j);
        }
    }

    cout << V << "\n";

    for(int i = 1; i <= V; i++){
        if(ke[i].size() != 0){
            cout << ke[i].size() << " ";
            for(int x : ke[i]){
                cout << x << " ";
            }
            cout << "\n";
        }
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