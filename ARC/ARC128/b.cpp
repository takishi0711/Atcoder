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
    int t;
    cin >> t;
    rep(ti,t) {
        vector<ll> color(3);
        rep(i,3) cin >> color[i];
        sort(color.begin(), color.end());
        ll ans = LINF;
        if ((color[2]-color[1])%3 == 0) {
            ll sub = color[2]-color[1];
            sub /= 3;
            ll now = sub;
            now += color[1] + (ll)2*sub;
            ans = min(ans, now);
        } 
        if ((color[1]-color[0])%3 == 0) {
            ll sub = color[1]-color[0];
            sub /= 3;
            ll now = sub;
            now += color[0] + (ll)2*sub;
            ans = min(ans, now);
        }
        if ((color[2]-color[0])%3 == 0) {
            ll sub = color[2]-color[0];
            sub /= 3;
            ll now = sub;
            now += color[0] + (ll)2*sub;
            ans = min(ans, now);
        }
        if (ans == LINF) cout << -1 << endl;
        else cout << ans << endl;
    }
    return 0;
}