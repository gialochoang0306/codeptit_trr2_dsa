#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    k = min(k, n - k);
    int fh = 0, sh = 0;

    for(int i = 0; i < k; i++){
        sh += a[i];
    }
    for(int i = k; i < n; i++){
        fh += a[i];
    }

    cout << abs(fh - sh) << "\n";
}


int  main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}