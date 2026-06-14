#include<bits/stdc++.h>
using namespace std;

int a[1000], n, k;


void backtrack(int m){
    if(m > k){
        for(int i = 1; i <= k; i++){
            cout << a[i] << ' ';
        }
        cout << "\n";
        return;
    }

    for(int i = n - k + m; i >= a[m - 1] + 1; i--){
        a[m] = i;
        backtrack(m + 1);
    }
}


int main(){

    int t;
    cin >> t;
    while(t--){
        cin >> n >> k;
        for(int i = 1; i <= k; i++){
            a[i] = i;
        }

        backtrack(1);
    }

    return 0;
    
}