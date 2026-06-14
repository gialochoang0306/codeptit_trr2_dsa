#include<bits/stdc++.h>
using namespace std;
string s;

void solve(){
    cin >> s;
    int n = s.length();
    int i = n - 1;
    while (i >= 0 && s[i] != '1') {
        i--;
    }
    if(i == -1){
        for(int j = 0; j < n; j++){
            cout << '1';
        }
        cout << "\n";
        return;
    }
    s[i] = '0';
    if(i + 1 < n){
        for(int j = i + 1; j < n; j++){ 
            s[j] = '1';
        } 
    } 
    cout << s << "\n";
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}