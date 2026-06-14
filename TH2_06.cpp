#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    long long tong = 0;
    stack<pair<int, int>> st;

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        int cntx = 1;
        while(!st.empty() && st.top().first < x){
            tong += st.top().second;
            st.pop();
        }
        if(!st.empty() && st.top().first == x){
            tong += st.top().second;
            cntx += st.top().second;
            st.pop();
            if(!st.empty()){
                tong++;
            }
        }
        else if(!st.empty()){
            tong++;
        }
        st.push({x, cntx});
    }
    cout << tong;
    return 0;
}