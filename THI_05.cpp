#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    if(n == 0){
        cout << 0 << "\n";
        return;
    }

    vector<pair<int, int>> cay;
    int md = 0;

    for(int i = 0; i < n; i++){
        int v;
        cin >>v ;
        auto it = lower_bound(cay.begin(), cay.end(), make_pair(v, 0),
                            [](const pair<int, int> &a, const pair<int, int> &b){
                                return a.first < b.first;
                            });

        if(it != cay.end() && it->first == v) continue;
        int d = 1;
        if(it != cay.end()){
            d = max(d, it->second + 1);
        }
        if(it != cay.begin()){
            d = max(d, prev(it)->second + 1);
        }

        cay.insert(it, {v, d});
        md = max(md, d);
    }
    cout << md << "\n";
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}