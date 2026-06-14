#include<bits/stdc++.h>
using namespace std;

void solve(){
    int m, n, k;
    cin >> m >> n >> k;
    vector<int> am(m);
    vector<int> an(n);

    for(int i = 0; i < m; i++){
        cin >> am[i];
    }

    for(int i = 0; i < n; i++){
        cin >> an[i];
    }

    int curr, count = 0;

    int im = 0, in = 0;
    while(im < m && in < n && count < k){
        if(am[im] <= an[in]){
            curr = am[im];
            im++;
            count++;
        }
        else{
            curr = an[in];
            in++;
            count++;
        }
    }

    while(im < m && count < k){
        curr = am[im];
        im++;
        count++;
    }

    while(in < n && count < k){
        curr = an[in];
        in++;
        count++;
    }

    cout << curr <<"\n";
}

int main(){

    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;

}