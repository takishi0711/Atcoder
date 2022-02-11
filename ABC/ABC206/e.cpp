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
    int l, r;
    cin >> l >> r;
    if (l == 1) l++;
    if (l > r) {
        cout << 0 << endl;
        return 0;
    }
    Sieve sieve(1000000);
    vector<vector<int>> soin(r+1);
    for (int i = l; i <= r; i++) {
        auto vec = sieve.factor(i);
        for (auto p : vec) soin[i].push_back(p.first);
    }
    ll ans = 0;
    for (int i = l; i <= r-1; i++) {
        int n = soin[i].size();
        rep(si,1<<n) {
            if (si == 0) continue;
            ll num = 1;
            rep(j,n) {
                if (si>>j&1) num *= soin[i][j];
            }
            ll sum = r/num - i/num;
            if (__builtin_popcount(si)%2 == 0) sum *= -1;
            ans += sum;
        }
        ans -= r/i - 1;
    }
    ans *= 2;
    cout << ans << endl;
    return 0;
}