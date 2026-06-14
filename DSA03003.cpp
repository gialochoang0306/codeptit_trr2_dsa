#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        sort(arr.begin(), arr.end());
        
        long long sum = 0;
        for (int i = 0; i < n; i++) {

            long long tmp = (1LL * arr[i] * i) % MOD;
            
            sum = (sum + tmp) % MOD;
        }
        
        cout << sum << "\n";
    }
    return 0;
}