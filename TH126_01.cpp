#include<bits/stdc++.h>
using namespace std;

int a[1000], vs[1000], n, k;

bool check(){
    return a[n] == k;
}

void backtrack(int m){
    if(m > n){
        if(check()){
            for(int i = 1; i <= n; i++){
                cout << a[i] << " ";
            }
            cout << "\n";
        }
        return;
    }

    for(int i = 1; i <= n; i++){
        if(!vs[i]){
            a[m] = i;
            vs[i] = 1;
            backtrack(m + 1);
            vs[i] = 0;
        }
    }
}

int main(){
    cin >> n >> k;
    backtrack(1);
    return 0;
}