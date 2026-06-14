#include<bits/stdc++.h>
using namespace std;

int st = 0;
string s;
vector<char> ans;

void op(char c){
    if(c == '<'){
        if(st > 0) st--;
    }
    else if(c == '>'){
        if(st < ans.size()) st++;
    }
    else if(c == '-'){
        if(st > 0){
            ans.erase(ans.begin() + st - 1);
            st--;
        }
    }
    else{
        ans.insert(ans.begin() + st, c);
        st++;
    }
}

int main(){
    cin >> s;
    for(size_t i = 0; i < s.length(); i++){
        op(s[i]);
    }

    for(int i = 0; i < ans.size(); i++){
        cout << ans[i];
    }
    return 0;
}