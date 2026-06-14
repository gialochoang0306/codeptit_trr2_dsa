#include<bits/stdc++.h>
using namespace std;
int a[100000], n;

bool check(){
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(a[i] == 1){
            cnt++;
        }
    }
    if(cnt % 2 == 1){
        return false;
    }
    else{
        return true;
    } 
}

void backtrack(int k) {
    if (k > n) {
        if(check()){
            for(int i = 1; i <= n; i++){
            cout << a[i] << " ";
            }
            cout << "\n";
        }
        return;
    }

    for (int i = 0; i <= 1; i++) {
        a[k] = i;
        backtrack(k + 1);
    }
}   

int main(){
    cin >> n;
    backtrack(1);
    return 0;
}


