#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    priority_queue<long long, vector<long long>, greater<long long>> pq;

    long long tmp;
    for(int i = 0; i < n; i++){
        cin >> tmp;
        pq.push(tmp);
    }
    long long tcost = 0;
    while(pq.size() > 1){
        long long sum = 0;
        sum += pq.top(); pq.pop();
        sum += pq.top(); pq.pop();
        tcost += sum;
        pq.push(sum);
    }
    cout << tcost << "\n";


}

int main() {
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}