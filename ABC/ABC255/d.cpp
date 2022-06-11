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
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    sort(a.begin(), a.end());
    vector<ll> suma(n+1);
    rep(i,n) {
        suma[i+1] = suma[i] + a[i];
    }
    rep(qi,q) {
        ll x;
        cin >> x;
        int idx = lower_bound(a.begin(), a.end(), x) - a.begin();
        ll ans = 0;
        ans += abs(x*idx - suma[idx]);
        ans += abs(x*(n-idx) - (suma[n] - suma[idx]));
        cout << ans << endl;
    }
    return 0;
}