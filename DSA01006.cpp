#include<bits/stdc++.h>
using namespace std;

int a[1000], vs[1000], n;

void backtrack(int k){
    if(k > n){
        for(int i = 1; i <= n; i++){
            cout << a[i];
        }
        cout << " ";
        return;
    }

    for(int i = n; i >= 1; i--){
        if(!vs[i]){
            a[k] = i;
            vs[i] = 1;
            backtrack(k + 1);
            vs[i] = 0;
        }
    }
}

int main(){

    int t;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1; i <= n; i++){
            vs[i] = 0;
        }

        backtrack(1);
        cout << "\n";
    }
    return 0;
}