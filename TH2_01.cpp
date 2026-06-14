#include <bits/stdc++.h>
using namespace std;

bool isop(string &s){
    return (s == "+" || s == "-" || s == "/" || s == "*");
}

void solve(){
    int n;
    cin >> n;
    vector<string> s(n);
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }

    stack<long long> st;

    for(int i = n - 1; i >= 0; i--){
        if(isop(s[i])){
            long long f = st.top(); st.pop();
            long long sec = st.top(); st.pop();
            long long res = 0;

            if(s[i] == "+") res = f + sec;
            else if(s[i] == "-") res = f - sec;
            else if(s[i] == "*") res = f * sec;
            else if(s[i] == "/") res = f / sec;

            st.push(res);
        }
        else{
            st.push(stoll(s[i]));
        }
    }
    cout << st.top() << "\n";

}

int main() {
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}