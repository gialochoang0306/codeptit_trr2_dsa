#include<bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> a;
vector<int> mask;
vector<vector<int>> res;
vector<vector<int>> vs;
string path = "DLRU";

bool isValid(int r, int c) {
    return (r >= 0 && r < n && c >= 0 && c < n && a[r][c] == 1 && !vs[r][c]);
}

void backtrack(int row, int col){
    if(row < 0 || row >= n || col < 0 || col >= n || a[row][col] == 0) return;

    if(row == n - 1 && col == n - 1){
        res.push_back(mask);
        return;
    }
// D
    if(isValid(row + 1, col)) {
        vs[row + 1][col] = 1;
        mask.push_back(0);
        backtrack(row + 1, col);
        mask.pop_back();
        vs[row + 1][col] = 0;
    }

    // L
    if(isValid(row, col - 1)) {
        vs[row][col - 1] = 1;
        mask.push_back(1);
        backtrack(row, col - 1);
        mask.pop_back();
        vs[row][col - 1] = 0;
    }

    // R
    if(isValid(row, col + 1)) {
        vs[row][col + 1] = 1;
        mask.push_back(2);
        backtrack(row, col + 1);
        mask.pop_back();
        vs[row][col + 1] = 0;
    }

    // U
    if(isValid(row - 1, col)) {
        vs[row - 1][col] = 1;
        mask.push_back(3);
        backtrack(row - 1, col);
        mask.pop_back();
        vs[row - 1][col] = 0;
    }
    
}

void solve(){
    cin >> n;
    a.resize(n);
    vs.resize(n);
    mask.clear();
    res.clear();
    for(int i = 0; i < n; i++){
        a[i].resize(n);
        vs[i].resize(n);
        vs[i].assign(n, 0);
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    vs[0][0] = 1;
    backtrack(0, 0);

    if(res.empty()){
        cout << -1 << "\n";
        return;
    }

    for(int i = 0; i < res.size(); i++){
        for(int x : res[i]){
            cout << path[x];
        }
        cout << " ";
    }
    cout << "\n";

}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}