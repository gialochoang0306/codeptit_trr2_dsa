#include<bits/stdc++.h>
using namespace std;

int cnt[101], a[105][105]; 


void case1(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < 2*m; i++){
        int tmp;
        cin >> tmp;
        cnt[tmp]++;
    }
    for(int i = 1; i <= n; i++){
            cout << cnt[i] << " ";
    }
    cout << "\n";
}

void case2(){
    int n, m;
    cin >> n >> m;
    cout << n << "\n";
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        a[u][v] = 1;
        a[v][u] = 1;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
}
int main(){
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT","w", stdout);
    int t;
    cin >> t;
    if(t == 1){
        case1();
    }
    else{
        case2();
    }

}