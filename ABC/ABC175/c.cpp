#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    ll x, k, d;
    cin >> x >> k >> d;
    x = abs(x);
    ll ans;
    if (x/d >= k) {
        ans = x - k*d;
        cout << ans << endl;
        return 0;
    }
    if ((k-x/d)%2 == 0) {
        ans = x - d*(x/d);
        cout << ans << endl;
        return 0;
    }
    else {
        ans = abs(x - d*(x/d) - d);
        cout << ans << endl;
    }
    return 0;
}