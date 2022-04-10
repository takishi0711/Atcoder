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
    ll n;
    cin >> n;
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }
    ll ans = LINF;
    for (ll a = 0; a*a*a <= n; a++) {
        ll l = 0, r = 1e6;
        while (l+1 < r) {
            ll c = (l+r)/2;
            ll d = a*a*a + a*a*c + a*c*c + c*c*c;
            if (d >= n) r = c;
            else l = c;
        }
        ll now = a*a*a + a*a*r + a*r*r + r*r*r;
        ans = min(ans, now);
    }
    cout << ans << endl;
    return 0;
}