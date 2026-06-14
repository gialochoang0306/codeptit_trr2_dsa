#include<bits/stdc++.h>
using namespace std;



void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int l = 0, r = n - 1;

    while(l <= r){
        int m = (l + r) / 2;
        if(arr[m] == k){
            cout << m + 1 << "\n";
            return;
        }
        else if(arr[m] >  k){
            r = m - 1;
        }
        else if(arr[m] < k){
            l = m + 1;
        }
    }
    cout << "NO\n";
}
int main(){

    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}