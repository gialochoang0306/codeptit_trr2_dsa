#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

long long power(long long n, long long k) {
    long long res = 1;
    n = n % MOD;
    while (k > 0) {

        if (k % 2 == 1) {
            res = (res * n) % MOD;
        }
        
        n = (n * n) % MOD;
        k /= 2;
    }
    return res;
}

void solve(){
    long long n, k;
    cin >> n >> k;
    cout << power(n, k) << "\n";
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}