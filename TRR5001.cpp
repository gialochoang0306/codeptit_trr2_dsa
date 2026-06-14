#include<bits/stdc++.h>
using namespace std;

int a[105][105], vs[105], pr[105], d[105], s, t, V;

void dijtra(){
    for(int i = 1; i <= V; i++){
        vs[i] = 0;
        pr[i] = -1;
        d[i] = 10000;
    }

    d[s] = 0;
    //loop start here
    for(int i = 1; i <= V; i++){


        int u = -1;
        int dmin = 10000;
        for(int j = 1; j <= V; j++){
            if(!vs[j] && d[j] < dmin){
                u = j;
                dmin = d[j];
            }
        }

        if(u == -1){
            break;
        }
        vs[u] = 1;

        for(int v = 1; v <= V; v++){
            if(!vs[v] && a[u][v] > 0 && a[u][v] <= 50){
                if(d[u]+ a[u][v] < d[v]){
                    d[v] = d[u] + a[u][v];
                    pr[v] = u;
                }
            }
        }

    }
}

int main(){

    freopen("DN.INP", "r", stdin);
    freopen("DN.OUT", "w",stdout);
    cin >> V >> s >> t;

    for(int i = 1; i <= V; i++){
        for(int j = 1; j <= V; j++){
            cin >> a[i][j];
        }
    }

    dijtra();

    if(d[t] == 10000){
        cout << 0 << "\n";
    }
    else{
        vector<int> path;

        int v = t;
        while(v != -1){
            path.push_back(v);
            v = pr[v];
        }
        reverse(path.begin(), path.end());
        cout << d[t] << "\n";
        for(int i = 0; i < path.size(); i++){
            cout << path[i] << " ";
        }
    }
}