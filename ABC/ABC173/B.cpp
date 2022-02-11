#include <bits/stdc++.h>
using namespace std;
using ll = long long;



int main() {
    int N;
    cin >> N;
    int a = 0, b = 0, c = 0, d = 0;
    string s;

    for (int i = 0; i < N; i++) {
        cin >> s;
        if (s == "AC") a++;
        if (s == "WA") b++;
        if (s == "TLE") c++;
        if (s == "RE") d++;
    }

    cout << "AC x " << a << endl;
    cout << "WA x " << b << endl;
    cout << "TLE x " << c << endl;
    cout << "RE x " << d << endl;
}