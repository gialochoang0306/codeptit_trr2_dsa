#include <bits/stdc++.h>
using namespace std;

bool check(string s, int bd, int kt){
    int ro = 0;
    for(int i = bd; i <= kt; i++){
        if(s[i] == ')') ro--;
        else if(ro == 0 && (s[i] == '+' || s[i] == '-')){
            return true;
        }
    }
    return false;
}
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while(t--){
        string s;
        getline(cin, s);
        string cl = "";
        for(char c : s){
            if(c != ' ') cl += c;
        }

        s = cl;
        bool ck = true;
        while(ck){
            ck = false;
            stack<int> st;
            vector<pair<int, int>> p;
            for(int i = 0; i < s.size(); i++){
                if(s[i] == '('){
                    st.push(i);
                }
                else if(s[i] == ')'){
                    p.push_back({st.top(), i});
                    st.pop();
                }
            }

            for(auto &c : p){
                int l = c.first;
                int r = c.second;
                bool dk = false;
                if(l == 0){
                    dk = true;
                }
                else if(s[l - 1] == '+'){
                    dk = true;
                }
                else if(s[l - 1] == '('){
                    dk = true;
                }
                else if(!check(s, l + 1, r - 1)){
                    dk = true;
                }
                if(dk == true){
                    s.erase(r, 1);
                    s.erase(l, 1);
                    ck = true;
                    break;
                }

            }
        }
        cout << s << "\n";
    }
    return 0;
}