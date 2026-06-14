#include<bits/stdc++.h>
using namespace std;

struct box{
    int L, W, H;
    friend istream &operator>>(istream &in, box &b){
        in >> b.L >> b.W >> b.H;
        return in;
    }
};

bool compareBoxes(const box &b1, const box &b2){
    return (b1.L * b1.W) > (b2.L * b2.W);
}

vector<box> a;

int main(){

    int n;
    cin >> n;
    a.resize(n);
    vector<int> dp(n, 1);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    sort(a.begin(), a.end(), compareBoxes);
    int maxst = -1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(a[i].L < a[j].L && a[i].W < a[j].W){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        maxst = max(dp[i], maxst);
    }

    cout << maxst << "\n";

    return 0;
}