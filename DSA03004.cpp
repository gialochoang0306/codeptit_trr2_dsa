#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        priority_queue<int, vector<int>, greater<int>> q;
        int n;
        cin >> n;
        for(int i = 0; i < n; i++){
            int tmp;
            cin >> tmp;
            q.push(tmp);
        }
        long long a = 0, b = 0;
        int flip = 0;
        while(n){
            if(flip){
                a = a * 10 + q.top(); q.pop();
                flip = 0;
                n--;
            }
            else{
                b = b * 10 + q.top(); q.pop();
                flip = 1;
                n--;
            }
        }   
        cout << a + b << "\n";
    }
    return 0;
}