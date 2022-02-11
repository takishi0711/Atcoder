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

ll dp[70][2][2];
ll n;
string ns;

string che(ll x) {
    string s;
    while (x > 0) {
        s += to_string(x%2);
        x /= 2;
    }
    reverse(s.begin(), s.end());
    ostringstream sout;
    sout << std::setfill('0') << std::setw(64) << s;
    string res = sout.str();
    return res;
}

ll f(ll x) {
    string nx = che(x);
    rep(i,65)rep(j,2)rep(k,2) dp[i][j][k] = 0;
    dp[0][0][0] = 1;
    rep(i,64) {
        if (ns[i] == '0') {
            if (nx[i] == '0') {
                { // 0入れ
                    rep(j,2)rep(k,2) dp[i+1][j][k] += dp[i][j][k];
                }
                { // 1入れ
                    dp[i+1][1][1] += dp[i][1][1];
                }
            } else {
                { // 0入れ
                    rep(j,2)rep(k,2) dp[i+1][1][k] += dp[i][j][k];
                }
                { // 1入れ
                    rep(j,2) dp[i+1][j][1] += dp[i][j][1];
                }
            }
        } else {
            if (nx[i] == '0') {
                { // 0入れ
                    rep(j,2)rep(k,2) dp[i+1][j][k] += dp[i][j][k];
                }
                { // 1入れ
                    rep(k,2) dp[i+1][1][1] += dp[i][1][k];
                }
            } else {
                { // 0入れ
                    rep(j,2)rep(k,2) dp[i+1][1][k] += dp[i][j][k];
                }
                { // 1入れ
                    rep(j,2)rep(k,2) dp[i+1][j][1] += dp[i][j][k];
                }
            }
        }
    }
    ll res = 0;
    res += dp[64][0][1];
    res += dp[64][1][1];
    return res;
}



int main() {
    ll l, r;
    cin >> n >> l >> r;
    ns = che(n);
    ll ans = f(r) - f(l-1);
    cout << ans << endl;
    return 0;
}