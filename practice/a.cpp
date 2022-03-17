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

const int MX = 60000;
ll dp[MX+5];

ll sqrt_(ll x) {
    ll l = 0, r = ll(3e9)+1;
    while (l+1 < r) {
        ll c = (l+r)/2;
        if (c*c <= x) l = c; else r = c;
    }
    return l;
}

void solve() {
    ll x;
    cin >> x;
    ll r = sqrt_(x);
    ll ans = 0;
    for (ll i = 1; i <= MX; i++) {
        ll l = i*i;
        if (l <= r) ans += dp[i]*(r-l+1);
    }
    cout << ans << endl;
}

int main() {
    dp[1] = 1;
    for (ll i = 1; i <= MX; i++) {
        for (ll j = i*i; j <= MX; j++) {
            if (i != j) dp[j] += dp[i];
        }
    }
    int T;
    cin >> T;
    rep(ti,T) solve();
    return 0;
}