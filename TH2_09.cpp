#include<bits/stdc++.h>
using namespace std;

int n;
int pdit[] = {2,3,5,7};
vector<long long> res;

void backtrack(long long curr, int len, int mask){
    if(len >= 4 && len <= n){
        if(mask == 15 && curr % 2 != 0){
            res.push_back(curr);
        }
    }

    if(len == n) return;

    for(int i = 0; i < 4; i++){
        int d = pdit[i];
        int newm = mask | (1 << i);
        backtrack(curr * 10 + d, len + 1, newm);
    }
}

int main(){
    cin >> n;
    backtrack(0, 0, 0);
    sort(res.begin(), res.end());
    for(long long x : res){
        cout << x << "\n";
    }

}