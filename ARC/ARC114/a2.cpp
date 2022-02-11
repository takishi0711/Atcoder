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
    vector<pair<ll,int>> factor(ll x) {
        vector<pair<ll,int>> res;
        for (int p : primes) {
            int y = 0;
            while (x%p == 0) x /= p, ++y;
            if (y != 0) res.emplace_back(p,y);
        }
        if (x != 1) res.emplace_back(x,1);
        return res;
    }
};

int main() {
    Sieve sieve(50);
    int n;
    cin >> n;
    vector<int> x(n);
    rep(i,n) cin >> x[i];
    auto vec = sieve.primes;
    ll ans = LINF;
    rep(i,1<<15) {
        ll now = 1;
        rep(j,15) {
            if (i>>j&1) now *= vec[j];
        }
        bool ok = true;
        rep(j,n) {
            if (__gcd(now,(ll)x[j]) == 1) ok = false;
        }
        if (ok) ans = min(ans, now);
    }
    cout << ans << endl;
    return 0;
}