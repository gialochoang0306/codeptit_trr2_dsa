#include<bits/stdc++.h>
using namespace std;

int V, a[105][105], deg[105];

void case1(){
    cin >> V;

    for(int i = 1; i <=V; i++){
        for(int j = 1; j <= V; j++){
            cin >> a[i][j];
            if(a[i][j]) deg[i]++;
        }
    }

    for(int i = 1; i <=V; i++){
        cout << deg[i] << " "; 
    }
}



void case2(){
    cin >> V;
    for(int i = 1; i <=V; i++){
        for(int j = 1; j <= V; j++){
            cin >> a[i][j];
        }
    }
    vector<pair<int,int>> res;

    for(int i = 1; i <= V; i++){
        for(int j = i+1; j<=V; j++){
            if(a[i][j]) res.push_back({i, j});
        }
    }

    cout << V << " " << res.size() << "\n";
    for(auto it : res){
        cout << it.first << ' ' <<it.second << "\n";
    }
}

int main(){
    int t;
    cin >> t;
    if(t==1){
        case1();
    }
    else{
        case2();
    }
}