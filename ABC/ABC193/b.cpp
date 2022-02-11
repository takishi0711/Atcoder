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
    vector<ll> a(n), p(n), x(n);
    rep(i,n) cin >> a[i] >> p[i] >> x[i];
    ll ans = LINF;
    rep(i,n) {
        if (x[i]-a[i] <= 0) continue;
        ans = min(ans, p[i]);
    }
    if (ans == LINF) ans = -1;
    cout << ans << endl;
    return 0;
}