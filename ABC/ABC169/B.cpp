#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll Max = 1e18;


int main() {
    int n;
    cin >> n;
    ll num = 1;
    bool ng = false;

    for (int i = 0; i < n; i++) {
        ll a;
        cin >> a;
        if (a == 0) {
            cout << 0 << endl;
            return 0;
        }
        if (ng || Max/num < a) ng = true;
        num *= a;
    }
    if (ng) cout << -1 << endl;
    else cout << num << endl;
    return 0;
}