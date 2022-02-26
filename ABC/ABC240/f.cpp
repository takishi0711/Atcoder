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

ll sa1(ll x) {
    return (x+1)*x/2;
}

ll sa2(ll l, ll r) {
    return sa1(r) - sa1(l-1);
}

int main() {
    int t;
    cin >> t;
    rep(ti,t) {
        int n, m;
        cin >> n >> m;
        vector<ll> x(n), y(n);
        rep(i,n) cin >> x[i] >> y[i];
        vector<ll> cnt_sum(n+1);
        rep(i,n) {
            cnt_sum[i+1] = cnt_sum[i] + y[i];
        }
        
        vector<ll> b(n+1);
        rep(i,n) {
            b[i+1] = b[i] + x[i]*y[i];
        }
        vector<ll> a(n+1);
        rep(i,n) {
            a[i+1] = a[i];
            a[i+1] += b[i]*(cnt_sum[i+1]-cnt_sum[i]);
            a[i+1] += x[i]*sa1(cnt_sum[i+1]-cnt_sum[i]);
        }
        vector<ll> dd;
        rep(i,n) {
            if (b[i] > 0 && b[i+1] < 0) {
                int idx = cnt_sum[i];
                idx += b[i]/abs(x[i]);
                dd.push_back(idx);
            }
        } 
        if (b[n] > 0) dd.push_back(cnt_sum[n]);
        ll ans = -LINF;
        if (dd.size() == 0) {
            ans = x[0];
        } else {
            for (ll con : dd) {
                ll idx = lower_bound(cnt_sum.begin(), cnt_sum.end(), con) - cnt_sum.begin();
                idx--;
                ll now = a[idx];
                now += (con-cnt_sum[idx])*b[idx];
                // now += x[idx]*(con-cnt_sum[idx]);
                now += x[idx]*sa1(con-cnt_sum[idx]);
                ans = max(ans, now);
            }
        }
        cout << ans << endl;
        // if (ti == 0) {
        //     cout << "cnt_sum" << endl;
        //     rep(i,n+1) {
        //         if (i == n) cout << cnt_sum[i] << endl;
        //         else cout << cnt_sum[i] << " ";
        //     }
        //     cout << "b" << endl;
        //     rep(i,n+1) {
        //         if (i == n) cout << b[i] << endl;
        //         else cout << b[i] << " ";
        //     }
        //     cout << "a" << endl;
        //     rep(i,n+1) {
        //         if (i == n) cout << a[i] << endl;
        //         else cout << a[i] << " ";
        //     }
        //     cout << "dd" << endl;
        //     rep(i,dd.size()) {
        //         if (i == dd.size()-1) cout << dd[i] << endl;
        //         else cout << dd[i] << " ";
        //     }
        // }
    }
    return 0;
}