#include<iostream>
#include<vector>
#include <string.h> // Sử dụng cho hàm memset
using namespace std;

const int MAXN = 1001; // Số lượng đỉnh tối đa cho phép
int n, m; // n: số lượng đỉnh đồ thị (m không được sử dụng trong code này)
vector<pair<int, int>> vt[MAXN]; // Danh sách kề: vt[u] lưu các cặp {đỉnh_kề_v, trọng_số_w}
bool visited[MAXN]; // Mảng đánh dấu các đỉnh đã được kết nạp vào cây khung (MST)

// Cấu trúc lưu trữ một cạnh của đồ thị
struct edge{
    int u, v, w;
};

int st; // Đỉnh xuất phát của thuật toán Prim

// Hàm khởi tạo và đọc dữ liệu đầu vào
void init(){
    cin >> n >> st; // Đọc số đỉnh (n) và đỉnh bắt đầu (st)
    
    // Đọc ma trận kề n x n
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            int x;
            cin >> x; // x là trọng số của cạnh nối giữa đỉnh i và đỉnh j
            
            // Nếu có cạnh (x != 0) và chỉ lấy phần tam giác trên (i <= j) của ma trận 
            // để tránh thêm cạnh trùng lặp cho đồ thị vô hướng
            if (x!=0 && i<=j){
                vt[i].push_back({j, x}); // Thêm cạnh vô hướng i - j
                vt[j].push_back({i, x});
            }
        }
    }
    // Khởi tạo mảng visited bằng false (chưa có đỉnh nào được thăm)
    memset(visited, false, sizeof(visited));
}

// Thuật toán Prim tìm Cây khung nhỏ nhất
void prim(int u){
    int d = 0; // Biến lưu tổng trọng số của Cây khung nhỏ nhất
    vector<edge> mst; // Danh sách chứa các cạnh thuộc MST
    
    visited[u] = true; // Đánh dấu đỉnh xuất phát u đã thuộc MST
    
    // Cây khung của một đồ thị liên thông n đỉnh sẽ có đúng n-1 cạnh
    while (mst.size() != n-1){
        int min_w = 1e9+7; // Khởi tạo trọng số nhỏ nhất là một số vô cực (rất lớn)
        int x, y; // x: đỉnh ngoài MST sẽ thêm vào, y: đỉnh đang xét nằm trong MST
        
        // Quét tìm cạnh có trọng số nhỏ nhất nối từ một đỉnh TRONG tập MST ra một đỉnh NGOÀI tập MST
        for (int i=1; i<=n; i++){
            if (visited[i]){ // Chỉ xét các đỉnh i đã nằm trong MST
                for (auto it : vt[i]){ // Xét các đỉnh kề với i
                    if (!visited[it.first]){ // Nếu đỉnh kề này chưa nằm trong MST
                        // Nếu cạnh này nhỏ hơn cạnh nhỏ nhất hiện tại, tiến hành cập nhật
                        if (it.second < min_w){
                            min_w = it.second;
                            y = i;          // Đỉnh xuất phát (trong MST)
                            x = it.first;   // Đỉnh đích (sắp được thêm vào MST)
                        }
                    }
                }
            }
        }
        
        // Thêm cạnh tối ưu vừa tìm được vào danh sách kết quả MST
        mst.push_back({x, y, min_w});
        visited[x] = true; // Đánh dấu đỉnh mới x đã được kết nạp vào tập MST
        d += min_w;        // Cộng dồn tổng trọng số
    }
    
    // In ra tổng trọng số của Cây khung nhỏ nhất
    cout << "dH = " << d << "\n";
    
    // In ra danh sách các cạnh thuộc Cây khung nhỏ nhất
    for (auto it : mst){
        // Hoán đổi để luôn in ra đỉnh có số hiệu nhỏ hơn trước (cho nhất quán/dễ nhìn)
        if (it.u > it.v) swap(it.u, it.v);
        cout << it.u << ' ' << it.v << '\n';
    }
}

int main(){
    // Các lệnh tối ưu hóa I/O để chương trình đọc/ghi dữ liệu nhanh hơn
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    init();     // Gọi hàm đọc dữ liệu
    prim(st);   // Gọi hàm chạy thuật toán Prim từ đỉnh st
}