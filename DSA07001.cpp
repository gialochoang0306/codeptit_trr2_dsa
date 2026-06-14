#include<bits/stdc++.h>
using namespace std;
int arr[1000], st = -1;


int main(){
    stringstream buffer;

    buffer << std::cin.rdbuf();
    string op;
    int num;
    while(buffer >> op){
        if(op == "show"){
            if(st == -1){
                cout << "empty\n";
            }
            else{
                for(int i = 0; i <= st; i++){
                    cout << arr[i] << " ";
                }
                cout << "\n";
            }
        }
        else if(op == "pop"){

            if(st > -1) st--;
        }
        else{
            buffer >> num;
            arr[++st] = num;
        }
    }
    return 0;
}