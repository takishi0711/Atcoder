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
    int n, m;
    cin >> n >> m;
    vector<int> s(n), t(m);
    rep(i,n) cin >> s[i];
    rep(i,m) cin >> t[i];
    int r = 0, l = 0;
    rep(i,n-1) {
        if (s[0] != s[i+1]) {
            l = i+1;
            break;
        }
    }
    for (int i = n-1; i >= 0; i--) {
        if (s[0] != s[i]) {
            r = n-1 - i + 1;
            break;
        }
    }
    int g = min(r, l);
    if (g == 0) g = INF;
    int now = s[0];
    ll ans = 0;
    bool first = true;
    rep(i,m) {
        if (t[i] == now) ans++;
        else {
            if (first) {
                ans += g+1;
                first = false;
            }
            else ans += 2;
            now ^= 1;
        }
    } 
    if (ans > INF) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}