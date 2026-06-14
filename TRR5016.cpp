#include<bits/stdc++.h>
using namespace std;

int d[105][105], nxt[105][105], V; 

void floyd(){
    for(int k = 1; k <= V; k++){
        for(int u = 1; u <= V; u++){
            for(int v = 1; v <= V; v++){
                if(d[u][k] != 10000 && d[k][v] != 10000){
                    if(d[u][v] > d[u][k] + d[k][v]){
                        d[u][v] = d[u][k] + d[k][v];
                        nxt[u][v] = nxt[u][k];
                    }
                }
            }
        }
    }   
}

int main(){
    freopen("DN.INP", "r", stdin);
    freopen("DN.OUT", "w", stdout);
    cin >> V;
    for(int i = 1; i <= V; i++){
        for(int j = 1; j <= V; j++){
            cin >> d[i][j];
            if(d[i][j] != 10000){
                nxt[i][j] = j;
            }
        }
    }

    floyd();

    int uAns, vAns;
    int maxd = -1;
    for(int i = 1; i <= V; i++){
        for(int j = 1; j <= V; j++){
            if(i != j && d[i][j] < 10000){
                if(d[i][j] > maxd){
                    maxd = d[i][j];
                    uAns = i;
                    vAns = j;
                }
            }
        }
    }


    if(maxd == -1){
        cout << 0;
    }else{
        cout << uAns << ' ' << vAns << " " << maxd<< "\n";
        while(uAns != vAns){
            cout << uAns << " ";
            uAns = nxt[uAns][vAns];
        }
        cout << vAns;
    }


}