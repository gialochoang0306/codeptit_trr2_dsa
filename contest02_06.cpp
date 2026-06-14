#include<bits/stdc++.h>
using namespace std;

int a[100], vs[300], n;
char c1, c2, minc, maxc;

void backtrack(int k){
    if(k > n){
        for(int i = 1; i <= n; i++){
            cout << (char)a[i];
        }
        cout << "\n";
        return;
    }

    for(int i = minc; i <= maxc; i++){
        if(vs[i] == 0){
            a[k] = i;
            vs[i] = 1;
            backtrack(k + 1);
            vs[i] = 0;
        }
    }
}

int main(){
    cin >> c1 >> c2;
    
    if(c1 < c2){
        minc = c1;
        maxc = c2;
    } else {
        minc = c2;
        maxc = c1;
    }

    n = maxc - minc + 1;

    for(int i = 0; i < 300; i++){
        vs[i] = 0;
    }

    backtrack(1);
}