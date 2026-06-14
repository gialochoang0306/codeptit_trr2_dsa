#include<bits/stdc++.h>
using namespace std;
long long MOD = 1000000007;

struct MAT
{
    long long mat[15][15];
};

long long n, k;

MAT mull(MAT a, MAT b){
    MAT c;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            c.mat[i][j] = 0;
            for(int l = 0; l < n; l++){
                c.mat[i][j] = (c.mat[i][j] + a.mat[i][l] * b.mat[l][j]) % MOD;
            }
        }
    }
    return c;
}

MAT powerM(MAT a, long long p){
    MAT res;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j){
                res.mat[i][j] = 1;
            }
            else{
                res.mat[i][j] = 0;
            }
        }
    }

    while(p > 0){
        if(p % 2 == 1) res = mull(res, a);
        a = mull(a, a);
        p /= 2;
    }
    return res;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n >> k;
        MAT a;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> a.mat[i][j];
            }
        }

        MAT x = powerM(a, k);

        long long sum = 0;
        for(int i = 0; i < n; i++){
            sum = (sum + x.mat[i][n - i - 1]) % MOD;
        }
        cout << sum << "\n";
    }
    return 0;
}