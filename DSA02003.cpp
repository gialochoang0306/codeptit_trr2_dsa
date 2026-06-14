#include<bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> a;
vector<int> mask;
vector<vector<int>> res;

void backtrack(int row, int col){
    if(row < 0 || row >= n || col < 0 || col >= n || a[row][col] == 0) return;

    if(row == n - 1 && col == n - 1){
        res.push_back(mask);
        return;
    }

        mask.push_back(0);
        backtrack(row + 1, col);
        mask.pop_back();

        mask.push_back(1);
        backtrack(row, col + 1);
        mask.pop_back();

}

void solve(){
    cin >> n;
    a.resize(n);
    mask.clear();
    res.clear();
    for(int i = 0; i < n; i++){
        a[i].resize(n);
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }

    backtrack(0, 0);

    if(res.empty()){
        cout << -1 << "\n";
        return;
    }

    for(int i = 0; i < res.size(); i++){
        for(int x : res[i]){
            if(x == 0) cout << "D";
            if(x == 1) cout << "R";
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
}