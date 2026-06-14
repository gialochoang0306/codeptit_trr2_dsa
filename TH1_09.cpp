#include<bits/stdc++.h>
using namespace std;
int MAX = 1000000;
int divs[1000022];




int main(){

    for(int i = 2; i <= MAX; ++i){
        divs[i] = 1;
    }
    divs[1] = 0;

    for(int i = 2; i <= MAX / 2; ++i){
        for(int j = i*2; j <= MAX; j += i){
            divs[j] += i;
        }
    }
    int a, b;
    cin >> a >> b;

    int cnt = 0;
    for(int i = a; i <= b; i++){
        if(divs[i] > i){
            cnt++;
        }
    }

    cout << cnt;
    return 0;

}