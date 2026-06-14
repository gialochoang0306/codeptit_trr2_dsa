#include<bits/stdc++.h>
using namespace std;

int n, mask[1000];

bool check(){
    if(mask[1] != 1) return false;
    if(mask[n] != 0) return false;

    for(int i = 1; i < n; i++){
        if(mask[i] == mask[i + 1] && mask[i] == 1) return false;
    }

    return true;
}
void backtrack(int k){
    if(k > n){
        if(check()){
            for(int i = 1; i <= n; i++){
                if(mask[i] == 1){
                    cout << "H";
                }
                else{
                    cout << "A";
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
void solve(){
    cin >> n;
    backtrack(1);


}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}