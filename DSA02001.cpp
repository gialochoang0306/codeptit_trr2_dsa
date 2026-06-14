#include<bits/stdc++.h>
using namespace std;


void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }


    while(!a.empty()){
        cout << "[";
        for(int i = 0; i < a.size(); i++){
            if(i != a.size() - 1){
                cout << a[i] << " ";
            }
            else{
                cout << a[i];
            }
        }
        cout << "]\n";
        if(a.size() == 1) break;
        vector<int> nx(a.size() - 1);

        for(int i = 0; i < nx.size(); i++){
            nx[i] = a[i] + a[i + 1];
        }
        a = nx;
    }
    
}
int main(){

    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}