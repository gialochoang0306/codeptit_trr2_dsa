#include<bits/stdc++.h>
using namespace std;
int arr[1001], st = -1;
int main(){
    int n;
    cin >> n;
    string op;
    int num;
    for(int i = 0; i < n; i++){
        cin >> op;
        if(op == "PRINT"){
            if(st == -1){
                cout << "NONE\n";
            }
            else{
                cout << arr[st];
                cout << "\n";
            }
        }
        else if(op == "POP"){

            if(st > -1) st--;
        }
        else{
            cin >> num;
            arr[++st] = num;
        }
    }
}