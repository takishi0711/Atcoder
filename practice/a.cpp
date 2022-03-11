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

using mint = modint998244353;

struct combination {
  vector<mint> fact, ifact;
  combination(int n):fact(n+1),ifact(n+1) {
    //assert(n < mod);
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) fact[i] = fact[i-1]*i;
    ifact[n] = fact[n].inv();
    for (int i = n; i >= 1; --i) ifact[i-1] = ifact[i]*i;
  }
  mint operator()(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fact[n]*ifact[k]*ifact[n-k];
  }
  mint p(int n, int k) {
    return fact[n]*ifact[n-k];
  }
} comb(1000005);

int main() {
    int n, m, b, w;
    cin >> n >> m >> b >> w;
    auto f = [&](int b) {
        vector d(n+1, vector<mint>(m+1));
        rep(h,n+1)rep(w,m+1) {
            rep(i,h+1)rep(j,w+1) {
                mint now = comb(i*j, b);
                now *= comb(h,i)*comb(w,j);
                if ((h-i+w-j)%2) now = -now;
                d[h][w] += now;
            }
        }
        return d;
    };
    auto db = f(b);
    auto dw = f(w);

    mint ans;
    rep(bi,n+1)rep(bj,m+1)rep(wi,n+1)rep(wj,m+1) {
        if (bi+wi > n) continue;
        if (bj+wj > m) continue;
        mint now = comb(n,bi)*comb(n-bi,wi);
        now *= comb(m,bj)*comb(m-bj,wj);
        now *= db[bi][bj];
        now *= dw[wi][wj];
        ans += now;
    }
    cout << ans.val() << endl;
    return 0;
}