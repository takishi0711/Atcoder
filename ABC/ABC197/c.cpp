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
    ll ans = LINF;
    rep(si,1<<n-1) {
        ll now = 0;
        ll res = 0;
        res |= a[0];
        rep(i,n-1) {
            if (si>>i&1) {
                now ^= res;
                res = a[i+1];
            } else {
                res |= a[i+1];
            }
        }
        now ^= res;
        ans = min(ans, now);
    }
    cout << ans << endl;
    return 0;
}