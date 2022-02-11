#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    int g;
    rep(i,n) {
        cin >> a[i];
        if (i == 0) g = a[i];
        else g = __gcd(g,a[i]);
    }
    if (g != 1) {
        cout << "not coprime" << endl;
        return 0;
    }
    while (true) {
        sort(a.begin(), a.end());
        int x = 1;
        bool t = true;
        rep(i,n) {
            if (x == 1 && i == n-1) {
                cout << "pairwise coprime" << endl;
                return 0;
            }
            if (t && a[i] != 1) {
                x = a[i];
                t = false;
                continue;
            }
            if (a[i] == 1) continue;
            
            a[i] %= x;
            if (a[i] == 0) {
                cout << "setwise coprime" << endl;
                return 0;
            }
        }
    }
    return 0;
}