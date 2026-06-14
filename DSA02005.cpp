#include<bits/stdc++.h>
using namespace std;

int n, a[100], vs[100];
string s;

void backtrack(int m){
    if(m > n){
        for(int i = 1; i <= n; i++){
            cout << s[a[i] - 1];
        }
        cout << " ";
        return;
    }

    for(int i = 1; i <= n; i++){
        if(!vs[i]){
            a[m] = i;
            vs[i] = 1;
            backtrack(m + 1);
            vs[i] = 0;
        }
    }
}

void solve(){

    cin >> s;
    n = s.length();
    backtrack(1);
    cout << "\n";

}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}