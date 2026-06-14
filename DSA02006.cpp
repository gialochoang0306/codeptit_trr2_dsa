#include<bits/stdc++.h>
using namespace std;

int n, k;
vector<int> a;
vector<vector<int>> res;
vector<int> current;


void backtrack(int idx, int sum) {

    if (sum == k) {
        res.push_back(current);
        return;
    }
    

    for (int i = idx; i < n; i++) {

        if (sum + a[i] <= k) {
            current.push_back(a[i]);      
            backtrack(i + 1, sum + a[i]);
            current.pop_back();
        }
    }
}

void solve() {
    cin >> n >> k;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());
    
    res.clear();
    current.clear();
    
    backtrack(0, 0);
    
    if (res.empty()) {
        cout << -1 << "\n";
        return;
    }
    
    for (int i = 0; i < res.size(); i++) {
        cout << "[";
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j];
            if (j < res[i].size() - 1) cout << " ";
        }
        cout << "] ";
    }
    cout << "\n";
}

int main() {
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}