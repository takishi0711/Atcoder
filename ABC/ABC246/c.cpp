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
    ll n, k, x;
    cin >> n >> k >> x;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    rep(i,n) {
        ll num = a[i]/x;
        if (k >= num) {
            a[i] -= x*num;
            k -= num;
        } else {
            a[i] -= x*k;
            k = 0;
        }
    }
    cerr << k << endl;
    sort(a.rbegin(), a.rend());
    ll ans = 0;
    rep(i,n) {
        if (i > k-1) ans += a[i];
    }
    cout << ans << endl;
    return 0;
}