#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    queue<int> q;
    for(int i = 0; i < k; i++){
        if(a[i] < 0){
            q.push(i);
        }
    }

    if(!q.empty()){
        cout << a[q.front()] << " ";
    }
    else{
        cout << 0 << " ";
    }

    for(int i = k; i < n; i++){
        while(!q.empty() && q.front() <= i - k ){
            q.pop();
        }
        if(a[i] < 0){
            q.push(i);
        }
        
        if(!q.empty()){
            cout << a[q.front()] << " ";
        }else{
            cout << 0 << " ";
        }
    }
}

int main() {
    solve();
    return 0;
}