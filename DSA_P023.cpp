#include<bits/stdc++.h>
using namespace std;
int a[1000], n, k;
int cnt = 1;

bool checkp(int n){
    if(n < 2) return false;
    if(n == 2) return true;

    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0) return false;
    }

    return true;
}

void backtrack(int m){

    if(m > k){
        if(checkp(cnt)){
            cout << cnt << ": ";

            for(int i = 1; i <= k; i++){
                cout << a[i] << ' ';
            }
            cout << "\n";
        }
        cnt++;
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
    return 0;
}