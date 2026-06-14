#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int, int> &a, pair<int, int> &b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    return a.second < b.second;
}
void solve(){
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);

    for(int i = 0; i < n; i++){
        cin >> a[i].first >> a[i].second;   
    }

    sort(a.begin(), a.end(), cmp);

    int cnt = 1;
    int current_end = a[0].second; 

    for (int i = 1; i < n; i++) {
        if (a[i].first >= current_end) {
            cnt++;
            current_end = a[i].second;
        }
    }
    

    cout << cnt << "\n";
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
