#include<bits/stdc++.h>
using namespace std;

int main(){

    long long n, arr[10000];
    cin >> n;
    for(long long i = 0; i < n; i++){
        cin >> arr[i];
    }

    long long a = 0, b = 0;

    int l = 0, r = n - 1;
    bool flip = true;

    while(l <= r){
        if(flip){
            if(arr[l] > arr[r]){
                a += arr[l];
                l++;
            }
            else{
                a += arr[r];
                r--;
            }
            flip = false;
        }
        else{
            if(arr[l] > arr[r]){
                b += arr[l];
                l++;
            }
            else{
                b += arr[r];
                r--;
            }
            flip = true;
        }
    }

    cout << a << " " << b;
    return 0;
}