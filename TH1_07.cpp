#include<bits/stdc++.h>
using namespace std;

long long len[100];
long cnta[100];

long long count(int n, long long k){
    if(k == 0) return 0;
    if(n == 0) return 1;
    if(n == 1) return 0;

    if(k <= len[n - 1]){
        return count(n - 1, k);

    }
    else{
        return cnta[n - 1] + count(n - 2, k - len[n - 1]);
    }

}

int main(){
    int t;
    cin >> t;
    while(t--){
        
        len[0] = 1;
        len[1] = 1;
        cnta[0] = 1;
        cnta[1] = 0;

        for(int i = 2; i <= 45; i++){
            len[i] = len[i - 1] + len[i - 2];
            cnta[i] = cnta[i - 1] + cnta[i - 2];
        }

        long long n, k;
        cin >> n >> k;

        cout << count(n, k) << "\n";
    }
}