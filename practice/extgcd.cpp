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

// {g,x,y}: ax+by=g
tuple<ll,ll,ll> extgcd(ll a, ll b) {
    if (b == 0) return {a,1,0};
    ll g, x, y;
    tie(g,x,y) = extgcd(b,a%b);
    return {g, y, x-a/b*y};
}

void solve() {
    ll n, s, k;
    cin >> n >> s >> k;
    ll g, x, y;
    tie(g,x,y) = extgcd(k,n);
    if (s%g != 0) {
        cout << -1 << endl;
        return;
    }
    n /= g;
    s /= g;
    k /= g;
    ll ans = ((x*-s)%n+n)%n;
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    rep(i,t) solve();
    return 0;
}