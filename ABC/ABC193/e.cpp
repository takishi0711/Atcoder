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
    int t;
    cin >> t;
    rep(qi, t) {
        ll x, y, p, q;
        cin >> x >> y >> p >> q;
        set<ll> used1, used2;
        ll ansm = -1, ansn = -1;
        {
            for (int n = 0; n < 1000; n++) {
                ll st = (2*x+2*y)*n + x - p;
                if (used1.count(st%(p+q))) {
                    ansm = -1;
                    break;
                } 
                used1.insert(st%(p+q));
                for (int z = st; z < st+y; z++) {
                    if (z < 0) continue;
                    if (z%(p+q) == 0) {
                        ansm = z/(p+q);
                    }
                }
                if (ansm != -1) break;
            }
        } 
        {
            for (int m = 0; m < 1000; m++) {
                ll st = (p+q)*m + p - x;
                if (used2.count(st%(2*x+2*y))) {
                    ansn = -1;
                    break;
                } 
                used2.insert(st%(2*x+2*y));
                for (int z = st; z < st+q; z++) {
                    if (z < 0) continue;
                    if (z%(2*x+2*y) == 0) {
                        ansn = z/(2*x+2*y);
                    }
                }
                if (ansn != -1) break;
            }
        }
        if (ansm == -1 && ansn == -1) {
            cout << "infinity" << endl;
        } else if (ansn == -1) {
            ll ans = (p+q)*ansm + p;
            cout << ans << endl;
        } else if (ansm == -1) {
            ll ans = (2*x+2*y)*ansn + x;
            cout << ans << endl;
        } else {
            ll ans1 = (p+q)*ansm + p;
            ll ans2 = (2*x+2*y)*ansn + x;
            cout << min(ans1, ans2) << endl;
        }
    }
    return 0;
}