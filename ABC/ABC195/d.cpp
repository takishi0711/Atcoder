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
    int n, m, q;
    cin >> n >> m >> q;
    vector<pair<ll,ll>> bag(n);
    rep(i,n) {
        cin >> bag[i].second >> bag[i].first;
    }
    sort(bag.rbegin(), bag.rend());
    vector<ll> x(m);
    rep(i,m) cin >> x[i];
    rep(qi,q) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        vector<ll> y;
        rep(i,m) {
            if (l <= i && i <= r) continue;
            y.push_back(x[i]);
        }
        sort(y.begin(), y.end());
        vector<bool> used(n);
        ll ans = 0;
        for (ll si : y) {
            rep(i,n) {
                if (!used[i] && bag[i].second <= si) {
                    ans += bag[i].first;
                    used[i] = true;
                    break;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}