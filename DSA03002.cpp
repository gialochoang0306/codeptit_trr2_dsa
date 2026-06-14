#include <iostream>
#include <string>

using namespace std;

int getMin(string s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '6') {
            s[i] = '5';
        }
    }
    return stoi(s);
}

int getMax(string s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '5') {
            s[i] = '6';
        }
    }
    return stoi(s);
}

int main() {
    string a, b;
    if (cin >> a >> b) {
        int min_sum = getMin(a) + getMin(b);
        int max_sum = getMax(a) + getMax(b);
        
        cout << min_sum << " " << max_sum << "\n";
    }
    return 0;
}