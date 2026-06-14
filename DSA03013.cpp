#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    int d;
    cin >> s >> d;

    vector<int> freq(27, 0);
    for(int i = 0; i < s.length(); i++){
        freq[s[i] - 'a']++;
    }

    int max = 0;
    for(int x : freq){
        if(x > max) max = x;
    }

    

}

int main() {
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}