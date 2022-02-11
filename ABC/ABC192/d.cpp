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
    string x;
    cin >> x;
    ll m;
    cin >> m;
    ll d = 0;
    int n = x.size();
    rep(i,n) {
        d = max(d, (ll)(x[i]-'0'));
    }
    reverse(x.begin(), x.end());
    if (n == 1) {
        if (x[0]-'0' > m) {
            cout << 0 << endl;
        } else {
            cout << 1 << endl;
        }
        return 0;
    }
    
    if (n == 2) {
        ll a = x[0]-'0';
        ll b = x[1]-'0';
        if (a+b*(d+1) > m) {
            cout << 0 << endl;
        } else {
            ll l = d+1, r = 10e18+1;
            while (l+1 < r) {
                ll c = (l+r)/2;
                if (a+b*c > m) r = c;
                else l = c;
            }
            ll ans = l-(d+1)+1;
            cout << ans << endl;
        }
        return 0;
    }
    
    ll res = 0;
    ll f = 1;
    rep(i,n) {
        res += f*(x[i]-'0');
        if (res > m) {
            cout << 0 << endl;
            return 0;
        }
        ll bf = f;
        f *= (d+1);
        if (i != n-1 && f > m) {
            cout << 0 << endl;
            return 0;
        }
        if (i != n-1 && f < bf) {
            cout << 0 << endl;
            return 0;
        }
    }
    ll l = d+1, r = 10e9+1;
    while (l+1 < r) {
        ll c = (l+r)/2;
        res = 0;
        f = 1;
        ll g = c;
        bool ok = true;
        rep(i,n) {
            res += f*(x[i]-'0');
            if (res > m) {
                ok = false;
                break;
            }
            if (!ok) break;
            ll bf = f;
            f *= g;
            if (i != n-1 && f > m) {
                ok = false;
                break;
            } 
            if (i != n-1 && f < bf) {
                ok = false;
                break;
            }
        }
        if (ok) l = c;
        else r = c;
    }
    ll ans = l-(d+1)+1;
    cout << ans << endl;
    return 0;
}