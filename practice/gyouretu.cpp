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
const int INF = 2001001001;
const ll LINF = 1001002003004005006ll;

using mint = modint1000000007;
using matrix = vector<vector<mint>>;

int n;

//行列の掛け算
matrix mul(matrix a, matrix b) {
    matrix res(n, vector<mint>(n,0));
    rep(i,n)rep(j,n)rep(k,n) {
        res[i][j] += a[i][k] * b[k][j];
    }
    return res;
}

//行列累乗(繰り返し二乗法)
matrix mPow(matrix m, ll k) {
    if (k == 0) {
        matrix res(n, vector<mint>(n,0));
        rep(i,n) res[i][i] = 1;
        return res;
    }
    if (k == 1) return m;
    if (k%2 == 1) return mul(m, mPow(m, k-1));
    matrix res = mPow(m, k/2);
    return mul(res, res);
}

int main() {
    ll k;
    cin >> n >> k;
    vector<vector<int>> a(n, vector<int>(n));
    rep(i,n)rep(j,n) cin >> a[i][j];
    matrix A(n, vector<mint>(n));
    rep(i,n)rep(j,n) A[i][j] = a[i][j];

    A = mPow(A, k);

    mint ans = 0;
    rep(i,n)rep(j,n) ans += A[i][j];
    cout << ans.val() << endl;
    return 0;
}