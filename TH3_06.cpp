#include <iostream>
#include <vector>

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

bool unionse(int a, int b){
    a = find_set(a);
    b = find_set(b);

    if(a != b){
        parent_arr[b] = a;
        return true;
    }
    return false;
}
void solve(){
    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        make_set(i);
    }

    bool fl = false;

    for(int i = 0; i < m; i++){
        int u,v;
        cin >> u >> v;
        if(!fl){
            if(!unionse(u,v)){
                fl = true;
            }
        }
    }

    if(fl){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}