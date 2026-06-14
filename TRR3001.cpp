#include<bits/stdc++.h>
using namespace std;

int V, a[105][105], vs[105], deg[105], k;

stack<int> st;
vector<int> res;
int start;

void dfs(int u){
    k++;
    vs[u] = 1;
    for(int i = 1; i <= V; i++){
        if(!vs[i] && a[u][i]){
            dfs(i);
        }
    }
}

void case1(){
    cin >> V;
    for(int i = 1; i <= V; i++){
        for(int j = 1; j <= V; j++){
            cin >> a[i][j];
        }
    }
    
    dfs(1);
    if(k != V){
        cout << 0 << "\n";
        return;
    }

    for(int i = 1; i <= V; i++){
        for(int j = 1; j <= V; j++){
            deg[i] += a[i][j];
        }
    }

    int odd = 0;
    for(int i = 1; i <= V; i++){
        if(deg[i] % 2 != 0) odd++;
    }

    if(odd == 0){
        cout << 1 << "\n";
    }
    else if(odd <= 2){
        cout << 2 << "\n";
    }
}


void ec(int start){
    st.push(start);
    while(!st.empty()){
        int u = st.top();
        bool found = false;

        for(int i = 1; i <= V; i++){
            if(a[u][i]){
                st.push(i);
                a[u][i] = a[i][u] = 0;
                found = true;
                break;
            }
        }
        if(!found){
            st.pop();
            res.push_back(u);
        }
    }

    for(int i = res.size() - 1; i >= 0; i--){
        cout << res[i] << " ";
    }
}

void case2(){
    cin >> V >> start;
    for(int i = 1; i <= V; i++){
        for(int j = 1; j <= V; j++){
            cin >> a[i][j];
        }
    }
    ec(start);



}

int main(){
    //freopen("CT.INP", "r", stdin);
    //freopen("CT.OUT", "w", stdout);
    int t;
    cin >> t;
    if(t==1){
        case1();
    }
    else{
        case2();
    }
}