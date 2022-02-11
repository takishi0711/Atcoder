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
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<ll> s1(n), s2(n);
    s1[0] = a[0];
    rep(i,n-1) {
        s1[i+1] = s1[i]+a[i+1];
    }
    s2[0] = s1[0];
    rep(i,n-1) {
        s2[i+1] = s2[i]+s1[i+1];
    }
    ll ans = 0;
    ll mx = -LINF;
    rep(i,n-1) {
        mx = max(mx,s1[i]);
        ll now = s2[i]+mx;
        ans = max(ans, now);
    }
    ans = max(ans,s2[n-1]);
    cout << ans << endl;
    return 0;
}