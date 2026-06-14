#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        stack<int> st;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                
                if (s[i] == '+') {
                    st.push(a + b);
                }
                else if (s[i] == '-') {
                    st.push(a - b);
                }
                else if (s[i] == '*') {
                    st.push(a * b);
                }
                else if (s[i] == '/') {
                    st.push(a / b);
                }
            } 
            else {
                st.push(s[i] - '0'); 
            }
        }

        cout << st.top() << "\n";
    }
    return 0;
}