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



int main() {
    int n;
    cin >> n;
    vector<vector<ll>> c(n, vector<ll>(n));
    rep(i,n)rep(j,n) cin >> c[i][j];
    vector<ll> a(n), b(n);
    rep(j,n) {
        ll mn = LINF;
        rep(i,n) mn = min(mn, c[i][j]);
        b[j] = mn;
    }
    rep(i,n) {
        a[i] = c[i][0]-b[0];
    }
    rep(j,n) {
        bool ok = true;
        rep(i,n) {
            if (c[i][j]-b[j] != a[i]) ok = false;
        }
        if (ok == false) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    rep(i,n) cout << a[i] << " ";
    cout << endl;
    rep(i,n) cout << b[i] << " ";
    cout << endl;
    return 0;
}