#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    cin >> s;
    stack<int> st;
    int frs, sec;
    for(int i = 0; i < s.length(); i++){
        if(isdigit(s[i])){
            st.push(s[i] - '0');
        }
        else{
            switch(s[i]){
                case '+':
                    sec = st.top(); st.pop();
                    frs = st.top(); st.pop();
                    st.push(frs + sec);
                    break;
                case '-':
                    sec = st.top(); st.pop();
                    frs = st.top(); st.pop();
                    st.push(frs - sec);
                    break;
                case '*':
                    sec = st.top(); st.pop();
                    frs = st.top(); st.pop();
                    st.push(frs * sec);
                    break;
                case '/':
                    sec = st.top(); st.pop();
                    frs = st.top(); st.pop();
                    st.push(frs / sec);
                    break;
            }
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