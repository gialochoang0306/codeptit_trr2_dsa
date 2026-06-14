#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        int arr[10000];
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }

        int cnt = 0;

        for(int i = 0; i < n - 1; i++){
            int mn = min(arr[i], arr[i + 1]);
            int mx = max(arr[i], arr[i + 1]);

            while(mn*2 < mx){
                cnt++;
                mn *= 2;
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}