#include<bits/stdc++.h>

using namespace std;

int a[10005]; 

void dq(int i, int n) {
    if (i >= n) return;
    
    dq(2 * i + 1, n);
    cout << a[i] << " ";
    dq(2 * i + 2, n);
}

void solve() {
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    dq(0, n);
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