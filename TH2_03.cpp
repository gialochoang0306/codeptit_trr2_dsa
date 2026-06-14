#include <bits/stdc++.h>
using namespace std;

long long lrec(vector<long long> &h){
    long long maxar = 0;
    stack<int> s;
    int n = h.size();

    for(int i = 0; i <= n; i++){
        long long curr = (i == n ? 0 : h[i]);
        while(!s.empty() && h[s.top()] > curr){
            long long hi = h[s.top()];
            s.pop();

            long long w = s.empty() ? i : (i - s.top() - 1);
            maxar = max(maxar, hi * w);
        }
        s.push(i);
    }
    return maxar;
}

int main() {
    long long n, m;
    cin >> m >> n;

    vector<long long> a(n);
    vector<long long> b(n);

    for(int i = 0; i < n; i++){
        cin >> a[i];
        b[i] = m - a[i];
    }

    long long maxy = lrec(a);
    long long maxb = lrec(b);

    cout << max(maxy, maxb);

    return 0;
}