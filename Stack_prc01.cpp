#include<bits/stdc++.h>

using namespace std;

bool isValid(string& s) {
    stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        } else {
            if (st.empty()) {
                return false;
            }
            
            char top = st.top();
            if ((c == ')' && top == '(') || (c == ']' && top == '[') ||(c == '}' && top == '{')) {
                st.pop();
            } else {
                return false;
            }
        }
    }
    return st.empty();
}

void solve() {
    string s;
    cin >> s;
    if (isValid(s)) {
        cout << "true\n";
    } else {
        cout << "false\n";
    }
}

int main() {
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    
    return 0;
}