#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<int>a(n), b(m);

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < m; i++){
        cin >> b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int maxw = 0;
    int tb = 0;

    for(int ta = 0; ta < n && tb < m; ta++){
        if(a[ta] > b[tb]){
            maxw++;
            tb++;
        }
    }
    cout << maxw - 1;
}