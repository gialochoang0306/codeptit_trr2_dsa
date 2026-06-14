#include<bits/stdc++.h>
using namespace std;
const long long mod  = 1e9+7;

long long power(long long bs, long long exp){
    long long res = 1;
    bs = bs % mod;
    while(exp > 0){
        if(exp % 2 == 1){
            res = (res*bs) % mod;
        }
        bs = (bs*bs) % mod;
        exp /= 2;
    }
    return res;
}

int main(){
    long long n;
    cin >> n;

    cout << power(3, n - 1);
}