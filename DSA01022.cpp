#include<bits/stdc++.h>
using namespace std;
int a[1000], b[1000], vs[100];
int n;
int pos = 1;
bool check(int n){
    for(int i = 1; i <= n; i++){
        if(a[i] != b[i]){
            return false;
        }
    }
    return true;
}

void backtrack(int k){
    if(k > n){
        if(check(n)){
            cout << pos << "\n";
        }
        else{
            pos++;
        }
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
void solve(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> b[i];
        vs[i] = 0;
    }

    pos = 1;
    backtrack(1);

}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}