#include<bits/stdc++.h>
using namespace std;

int money[] = { 1, 2, 5, 10, 20, 50, 100, 200, 500, 1000};


void solve(){
    int n;
    int cnt = 0;
    int p = 9;
    cin >> n;
    while(n){
        if(n - money[p] >= 0){
            n -= money[p];
            cnt++;
        }
        else{
            p--;
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
    return 0;
}
