#include<bits/stdc++.h>
using namespace std;

int mask[10000],a[10000], n, k, cnt = 0;
int calc(){
    int sum = 0;
    for(int i = 1; i <= n; i++){
        if(mask[i]) sum += a[i];
    }
    return sum;
}

void backtrack(int m){
    if(m > n){
        if(calc() == k){
            cnt++;
            for(int i = 1; i <= n; i++){
                if(mask[i]) cout << a[i] << " "; 
            }
            //for(int i = 1; i <= n; i++) cout << mask[i];
            cout << "\n";
        }
        return;
    }

    for(int i = 0; i <= 1; i++){
        mask[m] = i;
        backtrack(m + 1);
    }
}

int main(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    backtrack(1);
    cout << cnt;
    return 0;

}