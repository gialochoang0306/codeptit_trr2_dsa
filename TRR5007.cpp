#include<bits/stdc++.h>
using namespace std;

int V, s, t, a[105][105], vs[105], d[105], pr[105];

bool bellmanf(int s){
    for(int i = 1; i <= V ;i++){
        d[i] = 10000;
        pr[i] = -1;
    }

    d[s] = 0;
    for(int k = 1; k <= V -1; k++){
        for(int u = 1; u <= V; u++){
            for(int v =1; v <= V; v++){
                if(a[u][v] != 10000 && d[u] != 10000 && d[v] > d[u] + a[u][v]){
                    d[v] = d[u] + a[u][v];
                    pr[v] = u;
                }
            }
        }
    }

    for(int u = 1; u <= V; u++){
        for(int v = 1; v <= V; v++){
            if(a[u][v] != 10000 && d[u] != 10000 && d[v] > d[u] + a[u][v]){
                return false;
            }
        }
    }

    return true;
}

int main(){

    freopen("BN.INP", "r", stdin);
    freopen("BN.OUT", "w", stdout);
    cin >> V >> s >> t;

    for(int i = 1; i <= V; i++){
        for(int j = 1; j <= V; j++){
            cin >> a[i][j];
            if(a[i][j] == 0 && i != j) a[i][j] = 10000;
        }
    }

    bool check = bellmanf(s);
    if(!check){
        cout << -1;
    }
    else if(d[t] == 10000){
        cout << 0;
    }
    else{
        vector<int> path;
        int curr = t;
        while(curr != -1){
            path.push_back(curr);
            curr = pr[curr];
        }

        reverse(path.begin(), path.end());
        cout << d[t] << "\n";
        for(int x : path){
            cout << x << " ";
        }
    }


}