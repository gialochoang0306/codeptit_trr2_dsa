#include<bits/stdc++.h>
using namespace std;

int a[1000], n, k;

bool ps(long long x) {
    if (x < 0) return false;
    long long s = sqrt(x);
    return s * s == x;
}

bool isFib(long long n) {
    return ps(5 * n * n + 4) || ps(5 * n * n - 4);
}

bool check(){
    int sum = 0;
    for(int i = 1; i <= k; i++){
        sum += a[i];
    }
    if(isFib(sum)) return true;
    return false;

}

void backtrack(int m){
    if(m > k){
        if(check()){
            for(int i = 1; i <= k; i++){
                cout << a[i] << ' ';
            }
            cout << "\n";
        }
        
        return;
    }

    for(int i = a[m - 1] + 1; i <= n - k + m; i++){
        a[m] = i;
        backtrack(m + 1);
    }
}


int main(){

        cin >> n >> k;

        for(int i = 1; i <= n; i++){
            a[i] = i;
        }

        backtrack(1);

    
}