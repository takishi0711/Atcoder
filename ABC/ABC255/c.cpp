#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y);
#define chmin(x,y) x = min(x,y);
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};
const int INF = 1001001001;
const ll LINF = 1001002003004005006ll;
const double PI = acos(-1);



int main() {
    ll x, a, d, n;
    cin >> x >> a >> d >> n;
    x -= a;
    a -= a;
    if (d < 0) {
        d *= -1;
        x *= -1;
    }
    if (x <= 0) {
        cout << abs(x) << endl;
    } else if ((n-1)*d <= x) {
        cout << x - (n-1)*d << endl;
    } else {
        ll l = 1, r = n;
        while (l+1 < r) {
            ll c = (l+r)/2;
            if (x >= (c-1)*d) l = c;
            else r = c;
        }
        ll ans = min(abs((l-1)*d - x), abs((l)*d - x));
        cout << ans << endl;
    }
    return 0;
}