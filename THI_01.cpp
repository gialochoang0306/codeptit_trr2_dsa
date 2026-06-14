#include <bits/stdc++.h>
using namespace std;
int a[100], n, k;
int sum = 0;

bool checkp(int p){
    if(p <= 1) return false;
    if(p == 2) return true;

    for(int i = 2; i <= sqrt(p); i++){
        if(p % i == 0) return false;
    }
    return true;
}

bool check(){
    sum = 0;
    for(int i = 1; i <= k; i++){
        sum += a[i];
    }

    return checkp(sum);

}
void backtrack(int m){
    if(m > k){
        if(check()){
            for(int i = 1; i <= k; i++){
                cout << a[i] << " ";
            }
            cout << "\n";
        }
        return;
    }

    for(int i = a[m - 1] + 1; i <= n - k + m; i++){
        a[m] = i;
        backtrack(m + 1);
    }
}

int main() {
    cin >> n >> k;
    backtrack(1);
    return 0;
}