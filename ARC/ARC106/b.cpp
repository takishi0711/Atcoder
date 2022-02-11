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
    int n, m;
    cin >> n >> m;
    vector<ll> a(n), b(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    dsu da(n);
    rep(i,m) {
        int c, d;
        cin >> c >> d;
        c--; d--;
        da.merge(c,d);
    }
    vector<ll> asum(n), bsum(n);
    rep(i,n) {
        asum[da.leader(i)] += a[i];
        bsum[da.leader(i)] += b[i];
    }
    rep(i,n) {
        if (asum[i] != bsum[i]) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}