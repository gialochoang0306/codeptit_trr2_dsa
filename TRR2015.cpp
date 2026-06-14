#include<bits/stdc++.h>
using namespace std;

int V, a[105][105], b[105][105], k = 0;
int vs[105];
void dfs(int u){
    vs[u] = 1;
    k++;
    for(int i = 1; i <= V; i++){
        if(vs[i] == 0 && a[u][i] == 1){
            dfs(i);
        }
    }
}

void dfs2(int u){
    vs[u] = 1;
    k++;
    for(int i = 1; i <= V; i++){
        if(vs[i] == 0 && b[u][i] == 1){
            dfs2(i);
        }
    }
}

bool strongc() {
    for (int i = 1; i <= V; i++) {
        memset(vs, 0, sizeof(vs));
        k = 0;
        dfs(i);
        if (k < V) {
            return false;
        }
    }
    return true;
}

int main(){
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);
    cin >> V;
    for(int i = 1; i <= V; i++){
        for(int j = 1; j <= V; j++){
            int x;
            cin >> x;
            if(x == 1){
                a[i][j] = 1;
                b[i][j] = b[j][i] = 1;
            }
        }
    }


    if(strongc()){
        cout << 1 << "\n";
    }
    else{
        k = 0;
        memset(vs, 0, sizeof(vs));
        dfs2(1);
        if(k == V){
            cout << 2 << "\n";
        }
        else{
            cout << 0 << "\n";
        }

    }

}