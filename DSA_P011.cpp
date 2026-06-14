#include<bits/stdc++.h>
using namespace std;

char a[1000][1000];
int n, m;

void dfs(int i, int j){
    if (i < 0 || i >= n || j < 0 || j >= m || a[i][j] == '.') {
        return;
    }

    a[i][j] = '.';

    dfs(i + 1, j);
    dfs(i, j + 1);
    dfs(i - 1, j);
    dfs(i, j - 1);

}

void solve(){
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] == '#'){
                cnt++;
                dfs(i, j);
            }
        }
    }

    cout << cnt;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }

    solve();

    return 0;
}