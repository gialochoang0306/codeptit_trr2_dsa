#include<bits/stdc++.h>

using namespace std;

long long countPairs(int x, const vector<int>& Y, const vector<int>& cnt, int m) {
    if (x == 0) return 0;
    if (x == 1) return cnt[0];

    auto it = upper_bound(Y.begin(), Y.end(), x);
    long long ans = Y.end() - it;


    ans += cnt[0] + cnt[1];


    if (x == 2) {
        ans -= (cnt[3] + cnt[4]);
    }
    if (x == 3) {
        ans += cnt[2];
    }

    return ans;
}

void solve() {
    int n, m;
    cin >> n >> m;
    
    vector<int> X(n);
    for (int i = 0; i < n; i++) {
        cin >> X[i];
    }

    vector<int> Y(m);
    vector<int> cnt(5, 0);
    for (int i = 0; i < m; i++) {
        cin >> Y[i];
        if (Y[i] < 5) {
            cnt[Y[i]]++;
        }
    }

    sort(Y.begin(), Y.end());

    long long total_pairs = 0;
    for (int i = 0; i < n; i++) {
        total_pairs += countPairs(X[i], Y, cnt, m);
    }

    cout << total_pairs << "\n";
}

int main() {

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}