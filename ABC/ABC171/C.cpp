#include <bits/stdc++.h>
using namespace std;

string f(int64_t n) {
    if (n == 0) return "";
    n--;
    return f(n/26) + (char)('a' + n%26);
}

int main() {
    int64_t n;
    cin >> n;
    cout << f(n) << endl;
    return 0;
}