#include<bits/stdc++.h>
using namespace std;
int a[100000], n, k;

void backtrack(int m){
    if( m > k){
        for(int i = 1; i <= k; i++){
            cout << a[i];
        }
        cout << ' ';
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
        backtrack(1);

        cout << "\n";
    }
}