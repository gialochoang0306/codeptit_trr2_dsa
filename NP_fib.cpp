#include<bits/stdc++.h>
using namespace std;
int n, a[10000];
long long fib[1001];
int curr = 0;
long long cnt = 0;

void backtrack(int k){
    if(k > n){
        if(cnt == fib[curr]){
            cout << curr + 1 << ": ";
            for(int i = 1; i <= n; i++){
                cout << a[i] << " ";
            }
            cout << "\n";
            cnt++;
            curr++;
            if(curr == 1) curr++;

        }
        else{
            cnt++;
        }
        return;
    }

    for(int i = 0; i <= 1; i++){
        a[k] = i;
        backtrack(k + 1);
    }
}

void genf(){
    fib[0] = 0;
    fib[1] = 1;
    for(int i = 2; i < 93; i++){
        fib[i] = fib[i - 1] + fib[i - 2];
    }
}
int main(){
    cin >> n;
    genf();
    backtrack(1);

    return 0;
} 
