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
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    ll ans = 0;
    if (x == y) {
        rep(i,n) {
            if (a[i] == x) a[i] = 1;
            else a[i] = 0;
        }
        vector<pair<int, ll>> vec;
        ll cnt = 0;
        rep(i,n) {
            cnt++;
            if (i == n-1 || a[i] != a[i+1]) {
                vec.push_back(make_pair(a[i], cnt));
                cnt = 0;
            }
        } 
        for (auto [num, sz] : vec) {
            if (num == 1) ans += (ll)(sz+1)*sz/2;
        }
    } else {
        set<int> xst, yst, dame;
        rep(i,n) {
            if (a[i] < y || a[i] > x) dame.insert(i);
            if (a[i] == x) xst.insert(i);
            if (a[i] == y) yst.insert(i);
        }
        rep(i,n) {
            auto xit = xst.lower_bound(i);
            auto yit = yst.lower_bound(i);
            auto dameit = dame.lower_bound(i);
            if (xit == xst.end() || yit == yst.end()) {
                continue;
            }
            int xidx = *xit;
            int yidx = *yit;
            int dameidx;
            if (dameit == dame.end()) {
                dameidx = n;
            } else {
                dameidx = *dameit;
            }
            ans += max(0, dameidx-max(xidx,yidx));
        }
    }
    cout << ans << endl;
    return 0;
}