#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    vector<int> b = a;
    sort(b.begin(), b.end());
    bool flag = true;
    for(int i = 0; i < n; i++){
        if(!(a[i] == b[i] && a[n - i - 1] == b[n - i - 1] 
        || a[i] == b[n - i -1] && a[n - i -1] == b[i])){
            flag = false;
            break;
            }
    }

    string s = flag ? "Yes" : "No";
    cout << s;
    cout << "\n";
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}