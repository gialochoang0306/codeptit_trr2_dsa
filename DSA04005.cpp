#include <iostream>
using namespace std;

long long Fib[100];

char dq(int n, long long i) {
    if (n == 1) return 'A';
    if (n == 2) return 'B';

    long long len1 = Fib[n - 2];

    if (i <= len1) {
        return dq(n - 2, i);
    } 

    else {
        return dq(n - 1, i - len1);
    }
}

void solve() {
    int n;
    long long i;
    cin >> n >> i;
    cout << dq(n, i) << endl;
}

int main() {

    Fib[1] = 1;
    Fib[2] = 1;
    for (int j = 3; j <= 92; j++) {
        Fib[j] = Fib[j - 2] + Fib[j - 1];
    }

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}