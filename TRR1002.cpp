#include <bits/stdc++.h>
using namespace std;

void solve(int mode){

    int n;
    cin >> n;
    vector<vector<int>> b(n, vector<int>());
    int tmp;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> tmp;
            if(tmp == 1){
                b[i].push_back(j);
            }
        }
    }
    if(mode == 1){

        for(vector<int> &x : b){
            cout << x.size()<< " ";
        }
    }

    else if(mode == 2){
        cout << n << "\n";

        for(vector<int> &x : b){
            if(!x.empty()){
                cout << x.size() << " ";
                for(int ke : x){
                    cout << ke + 1 << " ";
                }
                cout << "\n";
            }
        }
    }

    
}

int main() {
    freopen("DT.INP", "r", stdin);freopen("DT.OUT", "w", stdout);
    
    
    int t;
    cin >> t;
    solve(t);
    return 0;
}