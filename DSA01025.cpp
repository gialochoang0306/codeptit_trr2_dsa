#include<bits/stdc++.h>
using namespace std;

int n, k, a[1000], vs[1000];

void backtrack(int m){
    if(m > k){
        for(int i = 1; i <= k; i++){
            cout << (char)('A' - 1 + a[i]);
        }
        cout << "\n";
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
        backtrack(1);

    }
    return 0;
}