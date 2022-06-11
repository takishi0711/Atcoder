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
const double PI = acos(-1);



int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(k);
    vector<bool> us(n+1);
    rep(i,k) {
        cin >> a[i];
        a[i]--;
        us[a[i]] = true;
    }
    vector<ll> x(n), y(n);
    rep(i,n) cin >> x[i] >> y[i];
    ll maxall = 0;
    rep(i,n) {
        if (us[i]) continue;
        ll mi = LINF;
        rep(j,k) {
            chmin(mi, (x[a[j]]-x[i])*(x[a[j]]-x[i]) + (y[a[j]]-y[i])*(y[a[j]]-y[i]));
        }
        chmax(maxall, mi);
    }
    double ans = sqrt(maxall);
    printf("%.10f\n", ans);
    return 0;
}