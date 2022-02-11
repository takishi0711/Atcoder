#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y);
#define chmin(x,y) x = min(x,y);
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};
const int INF = 1001001001;



int main() {
    ll n, x, m;
    cin >> n >> x >> m;
    vector<ll> a;
    vector<int> q(100005);
    ll d = x;
    a.push_back(x);
    ll t = n;
    ll ans = 0;
    ll tot = 0;
    ll point = 0;
    bool ok = false;
    while (1) {
        t--;
        d = (d*d)%m;
        cout << d << endl;
        if (d == 0) {
            rep(i,a.size()) ans += a[i];
            cout << ans << endl;
            return 0;
        }
        if (d == 1) {
            rep(i,a.size()) tot += a[i];
            ans = tot + n-ll(a.size());
            cout << ans << endl;
            return 0;
        }
        if (d == a.back()) {
            rep(i,a.size()) tot += a[i];
            ans = tot + (n-ll(a.size()))*d;
            cout << ans << endl;
            return 0;
        }
        if (q[d] == 1) {
            point = d;
            ok = true;
            break;
        }
        if (t == 0) break;
        a.push_back(d);
        q[d]++;
    }
    if (ok) {
        rep(i,a.size()) ans += a[i];
        n -= ll(a.size());
        ll po = 0;
        rep(i,a.size()) {
            if (a[i] == point) po = i;
        }
        ll loop = 0;
        for (int i = po; i < a.size(); i++) {
            loop += a[i];
        }
        ll ji = ll(a.size()) - po;
        ans += loop * (n/ji);
        cout << ans << endl;
        return 0;
    }
    if (t == 0) {
        rep(i,a.size()) ans += a[i];
    }
    else {
        ll p = a.size();
        //ll tot = 0;
        rep(i,a.size()) tot += a[i];
        ll y = n/p;
        //rep(i,y) ans += tot;
        ans += tot*y;
        n %= p;
        rep(i,n) ans += a[i];
    }
    cout << ans << endl;
    return 0;
}