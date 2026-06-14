#include<bits/stdc++.h>
using namespace std;

int a[100000], vs[100000], n, m;

bool check(){
    return a[n] == m;
}
void backtrack(int k){
    if(k > n){

        if(check()){
            for(int i = 1; i <= n; i++){
                cout << a[i] << ' ';
            }
            cout << "\n";
        }
        return;
    }

    for(int i = 1; i <= n; i++){
        if(vs[i] == 0){
            a[k] = i;
            vs[i] = 1;
            backtrack(k + 1);
            vs[i] = 0;
        }
    }
}

int main(){
        cin >> n >> m;

        for(int i = 1; i <= n; i++){
            vs[i] = 0;
        }

        backtrack(1);
}
