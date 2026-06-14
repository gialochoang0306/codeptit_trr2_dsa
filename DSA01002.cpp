#include <iostream>
#include <vector>

using namespace std;

int a[1000005];

bool IsLast(int a[], int n, int k) {
    for (int i = 0; i < k; i++) {
        if (a[i] != n - k + i + 1) return false;
    }
    return true;
}

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < k; i++) {
            cin >> a[i];
        }

        if (IsLast(a, n, k)) {
            for (int i = 1; i <= k; i++) {
                cout << i << ' ';
            }
            cout << "\n";
            continue;
        }

        int j = k - 1;
        while (j >= 0 && a[j] >= n - k + j + 1) {
            j--;
        }

        if (j >= 0) {
            a[j]++;
            for (int i = j + 1; i < k; i++) {
                a[i] = a[j] + i - j;
            }
        }

        for (int i = 0; i < k; i++) {
            cout << a[i] << ' ';
        }
        cout << "\n";
    }
    return 0;
}