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

vector<ll> yakusu(ll n) {
    vector<ll> res;
    for (ll i = 1; i*i <= n; i++) {
        if (n%i == 0) {
            res.push_back(i);
            if (n/i != i) res.push_back(n/i);
        }
    }
    sort(res.begin(), res.end());
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<ll> ans;
    ans.push_back(1);
    ans.push_back(2);
    Sieve sieve(1000000);
    for (int i = 3; i <= n; i++) {
        if (sieve.isPrime(i)) {
            ans.push_back(2);
        } else {
            auto vec = yakusu(i);
            ans.push_back(ans[vec[1]-1]+1);
        }
    }
    rep(i,n) cout << ans[i] << " ";
    cout << endl;
    return 0;
}