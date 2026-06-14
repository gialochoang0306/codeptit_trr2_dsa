#include<bits/stdc++.h>

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
    int V, E;
    cin >> V >> E;
    for(int i = 1; i <= V; i++){
        make_set(i);
    }
    for(int i = 0; i < E; i++){
        int u, v;
        cin >> u >> v;
        union_sets(u, v);
    }
    set<int> s;
    int cnt = 0;
    for(int i = 1; i <= V; i++){
        if(s.)
    }
    
}

int main(){

    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}