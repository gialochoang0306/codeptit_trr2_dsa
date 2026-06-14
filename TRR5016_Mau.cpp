#include <bits/stdc++.h>
using namespace std;

// Định nghĩa một số vô cực (Infinity) thay cho số 10000 để an toàn và rõ nghĩa hơn
const int INF = 1e9; 

int V;
int d[105][105];   // Ma trận d[i][j] lưu độ dài đường đi ngắn nhất từ đỉnh i đến đỉnh j
int nxt[105][105]; // Ma trận nxt[i][j] lưu đỉnh tiếp theo cần đi từ i để đến được j

// Thuật toán Floyd-Warshall để tìm đường đi ngắn nhất giữa mọi cặp đỉnh
void floyd() {
    for (int k = 1; k <= V; ++k) {           // k là đỉnh trung gian
        for (int i = 1; i <= V; ++i) {       // i là đỉnh xuất phát
            for (int j = 1; j <= V; ++j) {   // j là đỉnh đích
                // Nếu tồn tại đường đi i -> k và k -> j
                // Và đường đi vòng qua k ngắn hơn đường đi hiện tại từ i -> j
                if (d[i][k] < INF && d[k][j] < INF && d[i][j] > d[i][k] + d[k][j]) {
                    d[i][j] = d[i][k] + d[k][j]; // Cập nhật lại khoảng cách ngắn hơn
                    nxt[i][j] = nxt[i][k];       // Để đi từ i đến j, bước đầu tiên là đi theo hướng của i đến k
                }
            }
        }
    }
}

// Hàm truy vết và in đường đi từ u đến v
void printPath(int u, int v) {
    while (u != v) {
        cout << u << " ";
        u = nxt[u][v]; // Nhảy đến đỉnh tiếp theo trên đường đi ngắn nhất
    }
    cout << v; // In ra đỉnh đích cuối cùng
}

int main() {
    // Tối ưu hóa I/O trong C++ giúp đọc/ghi file nhanh hơn
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("DN.INP", "r", stdin);
    freopen("DN.OUT", "w", stdout);

    cin >> V;

    // Đọc dữ liệu đầu vào trực tiếp vào ma trận khoảng cách d
    for (int i = 1; i <= V; ++i) {
        for (int j = 1; j <= V; ++j) {
            cin >> d[i][j];
            
            // Nếu bằng 10000 và không phải đường chéo chính (i != j) thì tức là không có đường đi trực tiếp
            if (d[i][j] == 10000 && i != j) {
                d[i][j] = INF; 
            }
            
            // Khởi tạo mảng truy vết
            if (d[i][j] != INF && i != j) {
                nxt[i][j] = j; // Điểm tiếp theo để đi từ i đến j chính là j
            } else {
                nxt[i][j] = 0; // Không có đường đi
            }
        }
    }

    // Chạy thuật toán để tính toán mọi đường đi ngắn nhất
    floyd();

    int maxDist = -1;
    int uAns = 0, vAns = 0;

    // Tìm cặp đỉnh (u, v) có "đường đi ngắn nhất" mang giá trị lớn nhất
    for (int u = 1; u <= V; ++u) {
        for (int v = 1; v <= V; ++v) {
            if (u != v && d[u][v] < INF) { // Chỉ xét các đỉnh phân biệt và có thể đi tới nhau
                // Do vòng lặp for duyệt từ nhỏ đến lớn, cập nhật lớn hơn (>) tự động 
                // giữ lại cặp u, v nhỏ nhất nếu có nhiều đường đi cùng chiều dài maxDist.
                if (d[u][v] > maxDist) {
                    maxDist = d[u][v];
                    uAns = u;
                    vAns = v;
                }
            }
        }
    }

    // In kết quả theo yêu cầu bài toán
    if (maxDist == -1) {
        cout << 0; // Không có bất kỳ đường đi nào hợp lệ
    } else {
        cout << uAns << " " << vAns << " " << maxDist << "\n";
        printPath(uAns, vAns);
    }

    return 0;
}