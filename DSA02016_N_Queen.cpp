// N-queen problem
// i + j & i - j + n
#include<bits/stdc++.h>
using namespace std;
int n, board[100][100], cols[100], diag[500], a_diag[500], cnt = 0;

void print_out(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(board[i][j]){
                cout << "[Q]";
            }
            else{
                cout << "[ ]";
            }
        }
        cout << "\n";
    }
    cout << "\n";
}

bool isSafe(int i, int j){
    if(board[i][j] || cols[j]|| diag[i - j + n] || a_diag[i + j]) return false;
    return true;
}

void backtrack(int r){
    if(r == n){
        cnt++;
        //print_out();
        return;
    }

    for(int i = 0; i < n; i++){
        if(isSafe(r, i)){
            board[r][i] = 1;
            cols[i] = 1;
            diag[r - i + n] = 1;
            a_diag[r + i] = 1;

            backtrack(r + 1);

            board[r][i] = 0;
            cols[i] = 0;
            diag[r - i + n] = 0;
            a_diag[r + i] = 0;

        }
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cnt = 0;
        cin >> n;
        for(int i = 0; i < 100; i++){
            for(int j = 0; j < 100; j++){
                board[i][j] = 0;
            }
            cols[i] = 0;
        }

        for(int i = 0; i < 500; i++){
            diag[i] = 0;
            a_diag[i] = 0;
        }

        backtrack(0);

        cout << cnt << "\n";

    }

    return 0;
}