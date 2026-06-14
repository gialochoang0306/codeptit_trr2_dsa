#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

long long flip(long long n){
    long long temp = 0;
    while(n){
        temp = (temp * 10 + n % 10)  % MOD;
        n /= 10;
    }
    return temp % MOD;
}

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
    long long n;
    cin >> n;
    cout << power(n, flip(n)) << "\n";
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}