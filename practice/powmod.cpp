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

ll powmod(ll x, ll t, ll mod) {
    if (!t) return 1;
    x %= mod;
    ll r = powmod(x, t/2, mod);
    (r *= r) %= mod;
    if (t%2) (r *= x) %= mod;
    return r;
}

int main() {
    ll n, m;
    cin >> n >> m;
    int ans = (powmod(10, n, m*m)/m)%m;
    cout << ans << endl;
    return 0;
}