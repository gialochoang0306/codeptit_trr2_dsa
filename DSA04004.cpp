#include<bits/stdc++.h>
using namespace std;

void dq(long long n, long long k){
    long long mid = (long long)pow(2, n - 1);

    if(mid == k){
        cout << n << "\n";
        return;
    }
    else if(k < mid){
        dq(n - 1, k);
    }
    else if(k > mid){
        dq(n - 1, k - mid);
    }
}

void solve(){
    long long n, k;
    cin >> n >> k;
    dq(n, k);

}

int main(){
    int k;
    cin >> k;
    while(k--){
        solve();
    }
}