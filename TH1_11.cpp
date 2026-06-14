#include<bits/stdc++.h>
using namespace std;
int a[100], n, k;

bool check(){
    for(int i = 1; i < k; i++){
        if(a[i] > a[i + 1]) return false;
    }
    return true;
}

void backtrack(int m){
    if(m > k){
        for(int i = 1; i <= k; i++){
            cout << a[i] <<" ";
        }
        cout << "\n";
        return;
    }

    for(int i = a[m - 1]; i <= n; i++){
        a[m] = i;
        backtrack(m + 1);
    }
}


int main(){
    a[0] = 1;
    cin >> n >> k;
    backtrack(1);

    return 0;
}