#include<bits/stdc++.h>
using namespace std;
int cnt = 0;
int dq(int n){
    cnt++;
    if(n <= 1) return 1;
    return dq(n - 1) + dq(n - 1);
}
int main(){
    dq(4);
    cout << cnt;
}