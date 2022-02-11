#include <bits/stdc++.h>
using namespace std;
using ll = long long;



int main() {
    string s, t;
    cin >> s >> t;
    
    int num = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != t[i]) num++;
    }
    cout << num << endl;
}