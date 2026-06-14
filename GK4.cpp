#include<bits/stdc++.h>
using namespace std;

int a[1000005];

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    bool f = 0;

    for(int i = 1; i <= n; i++){
        int curr_m = a[i];
        int curr_min = a[i];

        for(int j = 1; i < m; j++){
            if(a[i +j] > curr_m) curr_m = a[i+j];
            if(a[i+j] < curr_min) curr_min = a[i + j];
        }
        if(curr_m - curr_min <= k){
            cout << i << "\n";
            f = 1;
        }
    }
    if(!f) cout << "NONE\n";
}