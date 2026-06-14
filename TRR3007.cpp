#include<bits/stdc++.h>
using namespace std;

int ch[105], vs[105], a[105][105], V, s;

bool check = false;
int cnt = 0;
void hmt(int k){
    for(int i = 1; i <= V; i++){


        if(a[ch[k - 1]][i] == 1){


            if(k > V && i == s){
                check = true;
                cnt++;
                ch[k] = s;
                for(int j = 1; j <= V + 1; j++){
                    cout << ch[j] << " ";
                }
                cout << "\n";
            }


            else if(!vs[i]){
                ch[k] = i;
                vs[i] = 1;
                hmt(k + 1);
                vs[i] = 0;

            }
        }
    }
}

int main(){
    freopen("CT.INP", "r", stdin);
    freopen("CT.OUT", "w", stdout);
    cin >> V >> s;
    for(int i = 1; i <= V; i++){
        for(int j = 1; j <= V; j++){
            cin >> a[i][j];
        }
    }


    ch[1] = s;
    hmt(2);
    cout << cnt;
    if(!check){
        cout << 0;
    }
}