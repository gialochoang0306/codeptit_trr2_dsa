#include<bits/stdc++.h>
using namespace std;

int n, a[1000], vs[1000], arr[1000];

void backtrack(int k){
    if(k > n){

        for(int i = 1; i <= n; i++){
            cout << arr[a[i]] << " ";
        }
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
        cin >> arr[i];
    }

    sort(arr + 1, arr + 1 + n);

    for(int i = 1; i <= n; i++){
        vs[i] = 0;
    }

    backtrack(1);

    return 0;
}