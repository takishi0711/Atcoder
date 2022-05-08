#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
// using P = pair<int,int>;
#define chmax(x,y) x = max(x,y);
#define chmin(x,y) x = min(x,y);
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};
const int INF = 1001001001;
const ll LINF = 2101002003004005006ll;
const double PI = acos(-1);

typedef double D;      // 座標値の型。doubleかlong doubleを想定
typedef complex<ll> P;  // Point
typedef pair<P, P> L;  // Line
typedef vector<P> VP;
const D EPS = 1e-9;    // 許容誤差。問題によって変える
#define X real()
#define Y imag()
#define LE(n,m) ((n) < (m) + EPS)
#define GE(n,m) ((n) + EPS > (m))
#define EQ(n,m) (abs((n)-(m)) < EPS)

// 内積　dot(a,b) = |a||b|cosθ
D dot(P a, P b) {
  return (conj(a)*b).X;
}
// 外積　cross(a,b) = |a||b|sinθ
ll cross(P a, P b) {
  return (conj(a)*b).Y;
}

// 多角形の符号付面積
ll area(const VP& ps) {
  ll a = 0;
  rep (i, ps.size()) a += cross(ps[i], ps[(i+1) % ps.size()]);
  return a / 2;
}

// 多角形の符号付面積8倍
ll area8(const VP& ps) {
  ll a = 0;
  rep (i, ps.size()) a += cross(ps[i], ps[(i+1) % ps.size()]);
  return a*4;
}

// 多角形の符号付面積2倍
ll area2(const VP& ps) {
  ll a = 0;
  rep (i, ps.size()) a += cross(ps[i], ps[(i+1) % ps.size()]);
  return a;
}

P inC() {
    ll x, y;
    cin >> x >> y;
    return P(x,y);
}

int main() {
    int n;
    cin >> n;
    VP vec(2*n), veco(n);
    rep(i,n) {
        vec[i] = inC();
        vec[i+n] = vec[i];
        veco[i] = vec[i];
    }
    ll all2 = area2(veco);
    vector<ll> sums(2*n+1);
    for (int i = 1; i <= 2*n; i++) {
        sums[i] = cross(vec[i-1], vec[(i) % (2*n)]);
    }

    ll ans = LINF;
    int l = 0;
    ll sum = sums[0];
    for (int r = 1; r <= n*2; r++) {
        sum += sums[r];
        while (l < r) {
            chmin(ans, abs(all2-(sum+cross(vec[r], vec[(l) % (2*n)]))*4));
            if (all2 > (sum+cross(vec[r], vec[(l) % (2*n)]))*4) break;
            l++;
            sum -= sums[l-1];
        }

    }
    cout << ans << endl;
    return 0;
}