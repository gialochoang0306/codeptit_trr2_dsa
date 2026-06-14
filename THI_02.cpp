#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n; 
    vector<int> a(3*n);

    for(int i = 0; i < a.size(); i++){
        cin >> a[i];
    }

    sort(a.begin(), a.begin() + 3*n/2);
    sort(a.begin() + 3*n/2 + 1, a.end(), greater<int>());

    long long fh = 0, sh = 0;
    int l = 0, r = a.size() - 1;
    int sz = a.size();
    while(sz != 3*n - n){
        if(a[l] - a[r]){
            
        }
    }
}