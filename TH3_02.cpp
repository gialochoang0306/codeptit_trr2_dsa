#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
int parent_arr[MAXN];
int sz[MAXN];

void make_set(int v) {
    parent_arr[v] = v;
    sz[v] = 1;
}

int find_set(int v) {
    if (v == parent_arr[v]) {
        return v;
    }
    return parent_arr[v] = find_set(parent_arr[v]); 
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    
    if (a != b) {
        if (sz[a] < sz[b]) {
            swap(a, b);
        }
        parent_arr[b] = a;
        sz[a] += sz[b];
    }
}

void solve(){

}

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i <= n; i++){
        make_set(i);
    }

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;

        union_sets(u, v);
    }
    int r1 = find_set(1);
    int sz1 = sz[r1];

    if(sz1 == n){
        cout << n << "\n";
        return 0;
    }

    int omx = 0;
    for(int i = 1; i <= n; i++){
        int ri = find_set(i);

        if(ri != r1){
            omx = max(omx, sz[ri]);
        }
    }

    cout << sz1 + omx << "\n";

    return 0;
}