#include<bits/stdc++.h>
using namespace std;

stack<char> l, r;
string s;

void op(char c){
    if(c == '-'){
        if(!l.empty()){
            l.pop();
        }
    }
    else if(c == '<'){
        if(!l.empty()){
            r.push(l.top());
            l.pop();
        }
    }
    else if(c == '>'){
        if(!r.empty()){
            l.push(r.top());
            r.pop();
        }
    }
    else{
        l.push(c);
    }
}

int main(){
    cin >> s;
    for(int i = 0; i < s.length(); i++){
        op(s[i]);
    }

    while(!l.empty()){
        r.push(l.top());
        l.pop();
    }
    while(!r.empty()){
        cout << r.top();
        r.pop();
    }
    return 0;
}