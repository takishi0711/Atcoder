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

using mint = modint;

struct Sieve {
    int n;
    vector<int> f, primes;
    Sieve(int n=1):n(n), f(n+1) {
        f[0] = f[1] = -1;
        for (ll i = 2; i <= n; i++) {
            if (f[i]) continue;
            primes.push_back(i);
            f[i] = i;
            for (ll j = i*i; j <= n; j += i) {
                if (!f[j]) f[j] = i;
            }
        }
    }
    bool isPrime(int x) { return f[x] == x;}
    vector<int> factorList(int x) {
        vector<int> res;
        while (x != 1) {
            res.push_back(f[x]);
            x /= f[x];
        }
        return res;
    }
    vector<P> factor(int x) {
        vector<int> fl = factorList(x);
        if (fl.size() == 0) return {};
        vector<P> res(1, P(fl[0], 0));
        for (int p : fl) {
            if (res.back().first == p) {
                res.back().second++;
            } else {
                res.emplace_back(p, 1);
            }
        }
        return res;
    }
    vector<pair<ll,int>> factorL(ll x) {
        vector<pair<ll,int>> res;
        for (int p : primes) {
            int y = 0;
            while (x%p == 0) x /= p, ++y;
            if (y != 0) res.emplace_back(p,y);
        }
        if (x != 1) res.emplace_back(x,1);
        return res;
    }
} prime(33000);

int powmod(int x, int t, int mod) {
    if (t == 0) return 1;
    ll r = powmod(x, t>>1, mod);
    r = r*r%mod;
    if (t&1) r = r*x%mod;
    return r;
}

void solve() {
    int k;
    cin >> k;
    if (k%2 == 0) k /= 2;
    k *= 9;
    if (gcd(10,k) != 1) {
        cout << -1 << endl;
        return;
    }
    auto f = prime.factorL(k);
    int t = k;
    for (auto [p,_] : f) {
        t = t/p*(p-1);
    }
    vector<int> d;
    for (int i = 1; i*i <= t; i++) {
        if (t%i) continue;
        d.push_back(i);
        d.push_back(t/i);
    }
    int ans = t;
    mint::set_mod(k);
    for (int x : d) if (mint(10).pow(x).val() == 1) {
        ans = min(ans, x);
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    rep(ti,t) solve();
    return 0;
}