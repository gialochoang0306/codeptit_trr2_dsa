#include<bits/stdc++.h>
using namespace std;
int n, k, a[100];
set<string> pre;
vector<string> s;

void backtrack(int m){
    if(m > k){
        for(int i = 1; i <= k; i++){
            cout << s[a[i] - 1] << " ";
        }
        cout << "\n";
        return;
    }

    for(int i = a[m - 1] + 1; i <= n - k + m; i++){
        a[m] = i;
        backtrack(m + 1);
    }
}

int main(){

    cin >> n >> k;
    string tmp;
    for(int i = 0; i < n; i++){
        cin >> tmp;
        pre.insert(tmp);
    }

    for(const string &name : pre){
        s.push_back(name);
    }
    n = s.size();


    backtrack(1);


    return 0;
}