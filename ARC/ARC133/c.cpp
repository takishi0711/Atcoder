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
    ll h, w, k;
    cin >> h >> w >> k;
    vector<ll> a(h), b(w);
    ll suma = 0, sumb = 0;
    rep(i,h) {
        cin >> a[i];
        suma += a[i];
        suma %= k;
    }
    rep(i,w) {
        cin >> b[i];
        sumb += b[i];
        sumb %= k;
    }
    if (suma != sumb) {
        cout << -1 << endl;
        return 0;
    }
    ll ans1 = 0;
    rep(i,h) {
        ll mx = (k-1)*w;
        ll pa = mx%k;
        if (pa >= a[i]) {
            ans1 += mx - (pa - a[i]);
        } else {
            mx -= k;
            mx += (a[i] - pa);
            ans1 += mx;
        }
    }
    ll ans2 = 0;
    rep(i,w) {
        ll mx = (k-1)*h;
        ll pa = mx%k;
        if (pa >= b[i]) {
            ans2 += mx - (pa - b[i]);
        } else {
            mx -= k;
            mx += (b[i] - pa);
            ans2 += mx;
        }
    }
    cout << min(ans1, ans2) << endl;
    return 0;
}