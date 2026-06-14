#include<bits/stdc++.h>

using namespace std;

long long merge(vector<long long>& a, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    
    vector<long long> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = a[l + i];
    for (int i = 0; i < n2; i++) R[i] = a[m + i + 1];

    long long ans = 0; 
    int i = 0, j = 0, k = l;
    
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            a[k++] = L[i++];
        } else {
            ans += (n1 - i);
            a[k++] = R[j++];
        }
    }
    
    while (i < n1) a[k++] = L[i++];
    while (j < n2) a[k++] = R[j++]; 
    
    return ans;
}

long long ms(vector<long long>& a, int l, int r) {
    long long ans = 0;
    if (l < r) {
        int m = l + (r - l) / 2;
        ans += ms(a, l, m);
        ans += ms(a, m + 1, r);
        ans += merge(a, l, m, r);
    }
    return ans;
}

int main() {
    
    int t;
    if (cin >> t) {
        while (t--) {
            int n;
            cin >> n;
            
            vector<long long> arr(n); 
            for (int i = 0; i < n; i++) {
                cin >> arr[i];
            }
            
            cout << ms(arr, 0, n - 1) << "\n"; 
        }
    }
    return 0;
}