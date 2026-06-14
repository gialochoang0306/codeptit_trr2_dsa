#include<bits/stdc++.h>
using namespace std;

int n, k, a[1000];

bool check(){
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(a[i] == 1) cnt++;
    }
    if(cnt == k){
        return true;
    }
    return false;
}

void backtrack(int m){
    if(m > n){
        if(check()){
            for(int i = 1; i <= n; i++){
                cout << a[i];
            }
            cout << "\n";
        }
        return;
    }
    for(int i = 0; i <= 1; i++){
        a[m] = i;
        backtrack(m + 1);
    }

}

int main(){

    int t;
    cin >> t;
    while(t--){
        cin >> n >> k;
        backtrack(1);

    }
    return 0;
}
