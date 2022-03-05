#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y);
#define chmin(x,y) x = min(x,y);
const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, -1, 0, 1 };
const int dx[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
const int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
const int INF = 1001001001;
const ll LINF = 1001002003004005006ll;
const double PI = acos(-1);

ll c2(ll n) {
    return n*(n+1)/2;
}

void solve() {
    int n, m;
    cin >> n >> m;

    ll b = 0, a = 0;
    ll ans = -LINF;
    rep(ni,n) {
        ll x, y;
        cin >> x >> y;
        ans = max(ans, a+b+x);
        if (x < 0 && b > 0) {
            ll i = b/-x;
            if (i < y) {
                ans = max(ans, a+b*i+x*c2(i));
            }
        }
        a += b*y + x*c2(y);
        b += x*y;
        ans = max(ans, a);
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    rep(ti,t) solve();
    return 0;
}