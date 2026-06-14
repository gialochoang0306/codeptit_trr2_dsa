#include<bits/stdc++.h>
using namespace std;

int n, a[10000];

void backtrack(int k){
    if(k > n){
        for(int i = 1; i <= n; i++){
            if(a[i] == 0){
                cout << "A";
            }
            else{
                cout << "B";
            }
        }
        cout << " ";
        return;
    }

    for(int i = 0; i <= 1; i++){
        a[k] = i;
        backtrack(k + 1);
    }
}

int main(){

    int t;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1; i <= n; i++) {
            a[i] = 0;
        }

        backtrack(1);
        cout << "\n";
    }

    return 0;
}