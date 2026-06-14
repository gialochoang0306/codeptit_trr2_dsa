#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> arr;
void solve(){
    cin >> n;
    arr.resize(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int maxe = arr[0], res = arr[0];
    for(int i = 0; i < n; i++){
        maxe = max(arr[i], maxe + arr[i]);
        res = max(res, maxe);
    }

    cout << res << "\n";

}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}