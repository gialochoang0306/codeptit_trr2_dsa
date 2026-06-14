#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

long long power(long long n, long long k){
    if(k == 0) return 1;
    n = n % MOD;
    long long temp = power(n, k/2);
    long long res = temp * temp % MOD;

    if(k % 2 == 0){
        return res;
    }else{
        return n * res % MOD;
    }
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
}