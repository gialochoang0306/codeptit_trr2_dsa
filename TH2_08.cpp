#include <bits/stdc++.h>
using namespace std;

vector<long long> luckyn;

void genluck(long long curr){
    if(curr > 4444444444LL) return;

    if(curr > 0){
        luckyn.push_back(curr);
    }
    genluck(curr * 10 + 4);
    genluck(curr * 10 + 7);
}

int main() {
    genluck(0);
    sort(luckyn.begin(), luckyn.end());

    long long l, r;
    cin >> l >> r;
    long long tsum = 0;
    while(l <= r){
        auto it = lower_bound(luckyn.begin(), luckyn.end(), l);
        long long nextluck = *it;
        long long endv = min(r, nextluck);
        long long cnt = endv - l + 1;
        tsum += cnt * nextluck;

        l = endv + 1;
    }
    cout << tsum << "\n";
    return 0;
}