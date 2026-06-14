#include<bits/stdc++.h>
using namespace std;

int a[1000], res[1000], n, k, cnt = 1;

bool check(){
    for(int i = 1; i <= k; i++){
        if(a[i] != res[i]) return false;
    }
    return true;
}

void backtrack(int m){
    if(m > k){
        if(check()){
            cout << cnt << "\n";
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
    int t;
    cin >> t;
    while(t--){

        cin >> n >> k;

        for(int i = 1; i <= n; i++){
            a[i] = i;
        }

        for(int i = 1; i <= k; i++){
            cin >> res[i];
        }
        backtrack(1);
        cnt = 1;
    }
}