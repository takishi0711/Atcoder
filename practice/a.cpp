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
} sieve(1e6);

int D, W;
struct Q {
    int l, r, i;
    Q(int l, int r, int i) : l(l), r(r), i(i) {}
    bool operator<(const Q& a) const {
        if (r/W != a.r/W) return r/W < a.r/W;
        return l < a.l;
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    D = sqrt(q)+1;
    W = n/D+1;

    vector<vector<P>> fs;
    rep(i,n) {
        fs.push_back(sieve.factor(a[i]));
    }

    vector<Q> qs;
    rep(i,q) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        qs.emplace_back(l, r, i);
    }
    sort(qs.begin(), qs.end());

    int l = 0, r = -1;
    vector<int> cnt(1e6);
    int wa = 0;
    auto add = [&](int i, int co=1) {
        for (auto [p,c] : fs[i]) {
            if (cnt[p] == 0) wa++;
            cnt[p] += c*co;
            cnt[p] %= 3;
            if (cnt[p] == 0) wa--;
        }
    };
    auto del = [&](int i) { add(i,2);};

    vector<bool> ans(q);
    for (auto [ql, qr, qi] : qs) {
        while (l < ql) { del(l); l++;}
        while (l > ql) { l--; add(l);}
        while (r > qr) { del(r); r--;}
        while (r < qr) { r++; add(r);}
        ans[qi] = wa == 0;
    }

    rep(i,q) {
        if (ans[i]) puts("Yes");
        else puts("No");
    }
    return 0;
}