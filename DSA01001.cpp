#include<bits/stdc++.h>
using namespace std;

void solve(){
    string bin;
    cin >> bin;

    int len = bin.length() - 1;
    while(len >= 0 && bin[len] == '1'){
        len--;
    }

    if(len == -1){
        for(int i = 0; i < bin.length(); i++){
            cout << '0';
        }
        cout << "\n";
        return;
    }

    bin[len++] = '1';
    for(len ; len < bin.length(); len++){
        bin[len] = '0';
    }

    cout << bin << "\n";
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}