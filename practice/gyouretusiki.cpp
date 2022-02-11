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

// ARC54 C 鯛焼き

ll mod_pow(ll x, ll p, ll MOD) {
    ll a = 1;
    while (p) {
        if (p%2) a = a*x%MOD;
        x = x*x%MOD;
        p/=2;
    }
    return a;
}

// mod_inverse
ll mod_inverse(ll a, ll m) {
    return mod_pow(a, m-2, m);
}

// long long 専用 行列式を求める関数
ll det(vector<vector<ll>> A, const ll MOD) {
    const int n = A.size();
    assert(n == (int)A[0].size());
    ll ans = 1;
    for (int i = 0; i < n; i++) {
        int pivot = -1;
        for (int j = i; j < n; j++) if (A[j][i]) {
            pivot = j;
            break;
        }
        if (pivot == -1) return 0;
        if (i!=pivot) {
            swap(A[i], A[pivot]);
            ans *= -1;
        }
        ll inv = mod_inverse(A[i][i], MOD);
        for (int j = i+1; j < n; j++) {
            ll c = A[j][i]*inv % MOD;
            for (int k = i; k < n; k++) {
                A[j][k] = (A[j][k] - c*A[i][k])%MOD;
            }
        }
        (ans *= A[i][i]) %= MOD;
    }
    if (ans < 0) ans += MOD;
    return ans;
}


int main() {
    int n;
    cin >> n;
    vector<vector<ll>> t(n, vector<ll>(n));
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    rep(i,n)rep(j,n) {
        t[i][j] = s[i][j]-'0';
    }
    if (det(t,2)) cout << "Odd" << endl;
    else cout << "Even" << endl;
    return 0;
}