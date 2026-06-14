#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<string> res;
    queue<string> q;

    q.push("0");
    q.push("1");

    int maxhal = n / 2;
    while(!q.empty()){
        string u = q.front();
        q.pop();

        string full = u;
        for(int i = u.length() - 1; i >= 0; i--){
            full += u[i];
        }
        res.push_back(full);

        if(u.length() < maxhal){
            q.push(u + "0");
            q.push(u + "1");
        }
    }

    //sort(res.begin(), res.end());
    for(string &s : res){
        cout << s << " ";
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