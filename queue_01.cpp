#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    queue<string> q;
    q.push("1");
    while(n--){
        string s = q.front();
        q.pop();
        cout << s << " ";

        q.push(s + "0");
        q.push(s + "1");

    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}