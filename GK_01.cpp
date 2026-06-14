#include<bits/stdc++.h>
using namespace std;

int mask[100], n;
vector<int> a;

void backtrack(int m){
    if(m > n){
        for(int i = 1; i <= n; i++){
            cout << a[mask[i]];
        }
        cout <<  "\n";
        return;

    }

    for(int i = 0; i < a.size(); i++){
        mask[m] = i;
        backtrack(m + 1);
    }
}

int main(){

    cin >> n;
    for(int i = 0; i < 3; i++){
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
    }

    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    backtrack(1);

}