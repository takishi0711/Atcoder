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

using mint = modint1000000007;

template<typename T>
struct Matrix {
    int h, w;
    vector<vector<T>> d;
    Matrix() {}
    Matrix(int h, int w, T val=0): h(h), w(w), d(h, vector<T>(w,val)) {}
    Matrix& unit() {
        assert(h == w);
        rep(i,h) d[i][i] = 1;
        return *this;
    }
    const vector<T>& operator[](int i) const { return d[i];}
    vector<T>& operator[](int i) { return d[i];}
    Matrix operator*(const Matrix& a) const {
        assert(w == a.h);
        Matrix r(h, a.w);
        rep(k,w)rep(i,h)rep(j,a.w) {
            r[i][j] += d[i][k]*a[k][j];
        }
        return r;
    }
    Matrix pow(ll t) const {
        assert(h == w);
        if (!t) return Matrix(h,h).unit();
        if (t == 1) return *this;
        Matrix r = pow(t>>1);
        r = r*r;
        if (t&1) r = r*(*this);
        return r;
    }
};

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    Matrix<mint> d(n,n), x(n,1);
    d.unit();
    rep(i,n) {
        int a;
        cin >> a;
        x[i][0] = a;
    }
    mint _m = mint(1)/m;
    mint _m2 = _m/2;
    rep(i,m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        d[a][a] -= _m;
        d[b][b] -= _m;
        d[a][a] += _m2;
        d[a][b] += _m2;
        d[b][a] += _m2;
        d[b][b] += _m2;
    }
    auto ans = d.pow(k) * x;
    rep(i,n) {
        cout << ans[i][0].val() << endl;
    }
    return 0;
}