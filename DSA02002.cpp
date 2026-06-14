#include<bits/stdc++.h>
using namespace std;


void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    vector<vector<int>> res;
    while(!a.empty()){
        res.push_back(a);
        if(a.size() == 1) break;
        vector<int> nx(a.size() - 1);

        for(int i = 0; i < nx.size(); i++){
            nx[i] = a[i] + a[i + 1];
        }
        a = nx;
    }
        for(int i = n - 1; i >= 0; i--){
            cout << "[";
            for(int j = 0; j < res[i].size(); j++){
                if(j != res[i].size() - 1){
                    cout << res[i][j] << " ";
                }
                else{
                    cout << res[i][j];
                }
            }
            if(!i){
                cout << "]";
            }
            else{
                cout << "] ";
            }
        }
        cout << "\n";
    
}
int main(){

    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}