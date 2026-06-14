#include<bits/stdc++.h>
using namespace std;

int n, m;
int a[300001];

int low, high, mid, ans;
int prv, wm, i;

bool check(int k){
    prv = 0;
    for(i = 0; i < n; i++){
        if(a[i] + k >= m){
            wm = a[i] + k - m;
            if(prv <= wm){

            }else{
                prv = max(prv, a[i]);
            }
        }else{
            if(a[i] + k < prv){
                return false;
            }
            prv = max(prv, a[i]);
        }
    }
    return true;
}

int main(){
    cin >> n >> m;
    for (i = 0; i < n; i++){
        cin >> a[i];
    }

    low = 0, high = m - 1, ans = m -1;
    while(low <= high){
        mid = low +(high - low)/2;
        if(check(mid)){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    cout << ans;


}