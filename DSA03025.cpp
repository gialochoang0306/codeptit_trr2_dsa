#include<bits/stdc++.h>
using namespace std;

typedef struct 
{
    int x1, x2;
}seg;

vector<seg> arr;
int n;

bool cmp(seg a, seg b){
    if(a.x1 == a.x2) return (a.x2 - a.x1) < (b.x1 - b.x2);

    return a.x1 < b.x1;
}
void solve(){
    arr.resize(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i].x1 >> arr[i].x2;
    }

    sort(arr.begin(), arr.end(), cmp);

    int cnt = 0;
    int left = -1;

    for(seg x : arr){
        if(x.x1 > left){
            cnt++;
            left = x.x2;
        }
    }
    cout << cnt << "\n";
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}