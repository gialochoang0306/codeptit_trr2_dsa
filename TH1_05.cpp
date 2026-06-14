#include<bits/stdc++.h>
using namespace std;
int a[1000], mask[1000], n, k;
struct sub{
    vector<int> idx;
    int sum;
};

bool cmp(sub &a, sub &b){
    if(a.sum != b.sum) return a.sum < b.sum;
    if(a.idx < b.idx) return true;

    return false;
}

vector<sub> res;

void backtrack(int m){
    if(m > n){
        sub curr;
        curr.sum = 0;
        for(int i = 1; i <= n; i++){
            if(mask[i] == 1){
                curr.idx.push_back(i);
                curr.sum += a[i];
            }
        }

        if(!curr.idx.empty() && curr.sum <= k){
            res.push_back(curr);
        }

        return;
    }
    for(int i = 0; i <= 1; i++){
        mask[m] = i;
        backtrack(m + 1);
    }
}


int main(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    backtrack(1);

    if(res.empty()){
        cout << -1;
    }
    else{
        sort(res.begin(), res.end(), cmp);

        for(sub s : res){
            for(int p : s.idx){
                cout << p << " ";
            }
            cout << "\n";
            cout << "Sum = " << s.sum << "\n";
        }
    }
    return 0;
}