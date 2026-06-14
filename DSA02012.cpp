#include<bits/stdc++.h>
using namespace std;

int cnt;
int n, m;
vector<vector<int>> a;

void backtrack(int row, int col){
    if(row >= n || row < 0 || col >= m || col < 0) return;

    if(row == n - 1 && col == m - 1){
        cnt++;
    }

    backtrack(row + 1, col);
    backtrack(row, col + 1);
}

void solve(){
    cnt = 0;
    cin >> n >> m;
    a.resize(n);
    for(int i = 0; i < n; i++){
        a[i].resize(m);
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }

    backtrack(0, 0);
    cout << cnt << "\n";


}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}