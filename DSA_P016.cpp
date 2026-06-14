#include<bits/stdc++.h>
using namespace std;

int score = -1;
int board[9][9], cols[1000], diag[1000], a_diag[1000], mask[9][9];

bool isSafe(int i, int j){
    if(board[i][j] || cols[j]|| diag[i - j + 8] || a_diag[i + j]) return false;
    return true;
}

int calc(){
    int sum = 0;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(board[i][j] == 1){
                sum += mask[i][j];
            }
        }
    }
    return sum;
}


void backtrack(int row){

    if(row == 8){
        int curr = calc();
        score = max(score, curr);
        return;
    }

    for(int col = 0; col < 8; col++){
        if(isSafe(row, col)){
            board[row][col] = 1;
            cols[col] = 1;
            diag[row - col + 8] = 1;
            a_diag[row + col] = 1;

            backtrack(row + 1);

            board[row][col] = 0;
            cols[col] = 0;
            diag[row - col + 8] = 0;
            a_diag[row + col] = 0;

        }
    }
}


void solve(){
    score = -1;
    for(int i = 0; i < 999; i++){
        cols[i] = 0;
        diag[i] = 0;
        a_diag[i] = 0;

    }

    
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            cin >> mask[i][j];
            board[i][j] = 0;
        }
    }

    backtrack(0);
    cout << score << "\n";
}

int main(){
    int t;
    cin >> t;
    int n = 1;
    while(t--){
        cout <<"Test " << n << ": ";
        n++;
        solve();
    }
}