#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    priority_queue<long long, vector<long long>, greater<long long>> q;
    for(int i = 0; i < n; i++){
        long long x;
        cin >> x;
        q.push(x);
    }

    long long cost = 0;

    while(q.size() > 1){
        int take;
        if(q.size() < k){
            take = q.size();
        }
        else{
            take = k;
        }

        long long mn = 0, mx = 0;
        long long curr = 0;

        for(int i = 0; i < take; i++){
            long long val = q.top(); q.pop();

            if(i == 0) mn = val;
            if(i == take - 1) mx = val;

            curr += val;
        }
        cost += (mx - mn);
        q.push(curr);
    }

    cout << q.top() << "\n" << cost << "\n";
}