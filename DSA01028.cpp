#include<bits/stdc++.h>
using namespace std;
int n, k;
vector<int>a;
set<int>pre;

void backtrack(int m){
    if(m > k){
        for(int i = 1; i <= k; i++){
            cout << a[i] << " ";
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
    int tmp;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> tmp;
        pre.insert(tmp);        
    }
    a.push_back(0);
    n = a.size();

    for(int x : pre){
        a.push_back(x);
    }

    backtrack(1);


}