#include <iostream>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    queue<string> q;
    q.push("4");
    q.push("5");
    

    while (n--) {
  
        string s = q.front();
        q.pop();
        

        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        cout << s + rev_s << " ";
        
        q.push(s + "4");
        q.push(s + "5");
    }
    cout << "\n";
}

int main() {
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}