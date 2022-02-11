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
    vector<P> xy(n);
    rep(i,n) cin >> xy[i].first >> xy[i].second;
    sort(xy.begin(), xy.end());
    ll ans = 0;
    map<P,ll> mp;
    rep(i,n) {
        for (int j = i+1; j < n; j++) {
            if (xy[i].second == xy[j].second) {
                ans += mp[P(xy[i].first, xy[j].first)];
                mp[P(xy[i].first, xy[j].first)]++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}