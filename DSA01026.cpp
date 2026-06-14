#include<bits/stdc++.h>
using namespace std;
int n, mask[1000];

bool check(){
    if(mask[1] != 1) return false;
    if(mask[n] != 0) return false;
    for(int i = 1; i < n; i++){
        if(mask[i] == 1 && mask[i + 1] == 1) return false;
    }

    for(int i = 1; i < n - 2; i++){
        if(mask[i] == 0 && mask[i + 1] == 0 && mask[i + 2] == 0 && mask[i + 3] == 0) return false;
    }

    return true;
}

void backtrack(int k){
    if(k > n){
        if(check()){
            for(int i = 1; i <= n; i++){
                if(mask[i] == 0){
                    cout << 6;
                }
                else{
                    cout << 8;
                }
            }
            cout << "\n";
        }
        return;
    }

    for(int i = 0; i <= 1; i++){
        mask[k] = i;
        backtrack(k + 1);
    }
}
int main(){
    cin >> n;
    backtrack(1);
}