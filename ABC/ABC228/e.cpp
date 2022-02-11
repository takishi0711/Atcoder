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

using mint = modint998244353;


ll modPow(ll a, ll n, ll p) {
    if (n == 0) return 1;
    if (n == 1) return a%p;
    if (n%2 == 1) return (a * modPow(a, n-1, p))%p;
    ll t = modPow(a, n/2, p);
    return (t*t)%p;
}

int main() {
    ll n, k, m;
    cin >> n >> k >> m;
    int mod = 998244353;
    ll x = modPow(k,n,mod-1);
    ll ans = modPow(m,x,mod);
    cout << ans << endl;
    return 0;
}