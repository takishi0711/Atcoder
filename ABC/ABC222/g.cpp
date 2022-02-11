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
        ll k;
        cin >> k;
        string s = to_string(k);
        string fi;
        ll ans = 0;
        rep(i,s.size()) {
            fi += '2';
            ans++;
        }
        ll fi_num = stol(fi);
        if (fi_num < k) {
            fi_num = fi_num*10 + 2;
            ans++;
        }
        map<ll,int> mp;
        ll x = fi_num%k;
        mp[x]++;
        bool ok = true;
        while (x != 0) {
            x = x*10+2;
            x %= k;
            ans++;
            mp[x]++;
            if (mp[x] == 2) {
                cout << -1 << endl;
                ok = false;
                break;
            }
        }
        if (ok) cout << ans << endl;
    }
    return 0;
}