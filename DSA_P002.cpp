#include<bits/stdc++.h>
using namespace std;
int n, a[10000], vs[10000], cnt = 1;

void backtrack(int k){
    if(k > n){
        cout << cnt << ": ";
        for(int i = 1; i <= n; i++){
            cout << a[i] << " ";
        }
        cnt++;
        cout << "\n";
        return; 
    }

    for(int i = 1; i <= n; i++){
        if(!vs[i]){
            a[k] = i;
            vs[i] = 1;
            backtrack(k + 1);
            vs[i] = 0;
        }
    }
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        a[i] = i;
    }
    backtrack(1);
}