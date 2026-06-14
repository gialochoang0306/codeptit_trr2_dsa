#include<bits/stdc++.h>
using namespace std;
// . # o v

int row, col;
int soi = 0, cuu = 0;
int cnto = 0, cntv = 0;
char farm[1000][1000];

void dfs(int i, int j){
    if(i < 0 || i >= row || j < 0 || j >= col || farm[i][j] == '#' ){
        return;
    }

    if(farm[i][j] == 'o') cnto++;
    if(farm[i][j] == 'v') cntv++;

    farm[i][j] = '#';

    dfs(i + 1, j);
    dfs(i - 1, j);
    dfs(i, j + 1);
    dfs(i, j - 1);
}   

void in(){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cout << farm[i][j] << " ";
        }
        cout  << "\n";
    }
}

int main(){
    cin >> row >> col;

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cin >> farm[i][j];
        }
    }

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(farm[i][j] == 'o' || farm[i][j] == 'v'){
                dfs(i, j);
                if(cnto > cntv){
                    cuu += cnto;
                }
                else{
                    soi += cntv;
                }
                cnto = 0;
                cntv = 0;
            }
        }
    }
    in();
    cout << cuu << ' ' << soi;
}