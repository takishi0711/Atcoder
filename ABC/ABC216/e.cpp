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
    int n;
    cin >> n;
    ll k;
    cin >> k;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    ll ans = 0;
    ll l = 0, r = 2e9+1;
    while (l+1 < r) {
        ll c = (l+r)/2;
        ll cnt = 0;
        ll score = 0;
        rep(i,n) {
            if (c > a[i]) continue;
            cnt += a[i]-c+1;
            score += (c+a[i])*(a[i]-c+1)/2;
        }
        if (cnt <= k) {
            ll plu = min((ll)n,k-cnt);
            rep(i,n) {
                if (plu == 0) break;
                if (a[i] >= max(0LL, c-1)) {
                    score += c-1;
                    plu--;
                    if (plu == 0) break;
                }
            }
            r = c;
            ans = max(ans, score);
        } else {
            l = c;
        }
    }
    cout << ans << endl;
    return 0;
}