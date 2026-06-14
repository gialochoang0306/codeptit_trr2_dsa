#include <bits/stdc++.h>
using namespace std;

int V, a[105][105], vs[105], dego[105], degi[105], k;

// DFS trên đồ thị vô hướng nền để kiểm tra liên thông yếu
void dfs(int u) {
    vs[u] = 1;
    k++;
    for (int i = 1; i <= V; i++) {
        // Xét cả a[u][i] và a[i][u] để bỏ qua chiều mũi tên
        if (!vs[i] && (a[u][i] || a[i][u])) {
            dfs(i);
        }
    }
}

// Hàm kiểm tra liên thông yếu
bool lt_yeu() {
    memset(vs, 0, sizeof(vs));
    k = 0;
    
    // Chỉ cần xuất phát từ đỉnh 1 là đủ để quét toàn bộ đồ thị
    dfs(1);
    
    return k == V; 
}

void case1() {
    cin >> V;
    
    // Khởi tạo lại mảng bậc
    memset(dego, 0, sizeof(dego));
    memset(degi, 0, sizeof(degi));

    // Gộp thao tác đọc và đếm bậc để tối ưu độ phức tạp
    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= V; j++) {
            cin >> a[i][j];
            if (a[i][j]) {
                dego[i]++; // Số 1 trên hàng là bán bậc ra
                degi[j]++; // Số 1 trên cột là bán bậc vào
            }
        }
    }

    if (!lt_yeu()) {
        cout << 0 << "\n";
        return;
    }

    int cnt = 0;

    for (int i = 1; i <= V; i++) {
        // Chênh lệch bậc > 1 => Không thỏa mãn Euler / Nửa Euler
        if (abs(dego[i] - degi[i]) > 1) {
            cout << 0 << "\n";
            return;
        }
        // Ghi nhận các đỉnh có chênh lệch bậc đúng bằng 1
        if (abs(dego[i] - degi[i]) == 1) cnt++;
    }

    // Kết luận dựa trên số đỉnh có chênh lệch bậc
    if (cnt == 0) {
        cout << 1 << "\n";
    } else if (cnt == 2) {
        cout << 2 << "\n";
    } else {
        cout << 0 << "\n";
    }
}

stack<int> st;
vector<int> res;

void ce(int start){
    st.push(start);
    while(!st.empty()){
        int u = st.top();
        bool found = false;

        for(int i = 1; i <= V; i++){
            if(a[u][i]){
                st.push(i);
                a[u][i] = 0;
                found = true;
                break;
            }
        }
        if(!found){
            res.push_back(u);
            st.pop();
        }
    }

    for(int i = res.size() - 1; i >= 0; i--){
        cout << res[i] << " ";
    }
}

void case2(){
    int start;
    cin >> V >> start;
    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= V; j++) {
            cin >> a[i][j];
        }
    }

    ce(start);


}
int main() {
    freopen("CT.INP", "r", stdin);
    freopen("CT.OUT", "w", stdout);
    
    int t;
    if (cin >> t && t == 1) {
        case1();
    }
    else{
        case2();
    }
    return 0;
}