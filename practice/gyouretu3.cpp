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

// ARC050 C - LCM 111

using matrix = vector<vector<ll>>;

ll mod_pow(ll x, ll p, ll MOD) {
    ll a = 1;
    while (p) {
        if (p%2) a = (a*x)%MOD;
        x = (x*x)%MOD;
        p /= 2;
    }
    return a;
}

matrix identity(int n) {
    matrix A(n, vector<ll>(n));
    rep(i,n) A[i][i] = 1;
    return A;
}

matrix mul(const matrix &A, const matrix &B, const ll MOD) {
    matrix C(A.size(), vector<ll>(B[0].size()));
    rep(i,C.size())rep(j,C.size())rep(k,A[i].size()) {
        C[i][j] += A[i][k] * B[k][j];
        C[i][j] %= MOD;
    }
    return C;
}

matrix pow(const matrix &A, ll e, const ll MOD) {
    if (e == 0) return identity(A.size());
    if (e == 1) return A;
    if (e%2 == 0) {
        matrix tmp = pow(A, e/2, MOD);
        return mul(tmp, tmp, MOD);
    } else {
        matrix tmp = pow(A, e-1, MOD); 
        return mul(A, tmp, MOD);
    }
}

int main() {
    ll A, B, M;
    cin >> A >> B >> M;
    ll G = gcd(A, B);

    matrix mat(2, vector<ll>(2));
    mat[0][0] = mod_pow(10, G, M), mat[0][1] = 1;
    mat[1][1] = 1;
    mat = pow(mat, B/G, M);
    ll b = mat[0][1];

    mat[0][0] = 10, mat[0][1] = 1;
    mat[1][0] = 0, mat[1][1] = 1;
    mat = pow(mat, A, M);
    ll a = mat[0][1];

    cout << a*b%M << endl;
    return 0;
}