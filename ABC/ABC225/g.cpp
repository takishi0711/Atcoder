#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y);
#define chmin(x,y) x = min(x,y);
const int di[] = {-1, 1, 1, -1};
const int dj[] = {1, -1, 1, -1};
const int INF = 1001001001;
const ll LINF = 1001002003004005006ll;
const double PI = acos(-1);



int main() {
    int h, w;
    cin >> h >> w;
    ll c;
    cin >> c;
    vector<vector<ll>> a(h, vector<ll>(w));
    rep(i,h)rep(j,w) cin >> a[i][j];
    ll ans = 0;
    vector<vector<bool>> used(h, vector<bool>(w));
    rep(i,h)rep(j,w) {
        if (a[i][j]-c*2 >= 0) {
            used[i][j] = true;
            continue;
        }
        bool ok = false;
        rep(dir,4) {
            int ni = i+di[dir], nj = j+dj[dir];
            if (ni<0||ni>=h||nj<0||nj>=w) continue;
            if (a[i][j]+a[ni][nj]-c*3 >= 0) ok = true;
        }
        if (ok) {
            used[i][j] = true;
        }
    }
    rep(i,h)rep(j,w) {
        if (used[i][j]) {
            ans += a[i][j];
            ans -= c*2;
        }
        if (i == 0) continue;
        rep(dir,4) {
            int ni = i+di[dir], nj = j+dj[dir];
            if (ni<0||ni>=h||nj<0||nj>=w) continue;
            if (ni > i) continue;
            if (used[ni][nj]) ans += c;
        }
    }
    cout << ans << endl;
    return 0;
}