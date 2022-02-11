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

ll dp[25][2][2];
ll n;
string ns;

ll f(ll x) {
    ostringstream sout;
    sout << std::setfill('0') << std::setw(19) << x;
    string nx = sout.str();
    rep(i,21)rep(j,2)rep(k,2) dp[i][j][k] = 0;
    dp[0][0][0] = 1;
    rep(i,19)rep(j,2)rep(k,2) {
        int ni = i+1, nj = j, nk = k;
        { // 0入れ
            if (nx[i] == '1') dp[i+1][1][k] += dp[i][j][k];
            else dp[i+1][j][k] += dp[i][j][k];
        } // 1入れ
        {
            if (ns[i] == '1') {
                if (nx[i] == '1') {
                    dp[i+1][j][1] += dp[i][j][k];
                } else {
                    if (j == 1) dp[i+1][1][1] += dp[i][j][k];
                }
            } else {
                if (k == 1) {
                    if (nx[i] == '1') {
                        dp[i+1][j][1] += dp[i][j][k];
                    } else {
                        if (j == 1) dp[i+1][1][1] += dp[i][j][k];
                    }                    
                }
            }
        }
    }
    ll res = 0;
    res += dp[19][0][1];
    res += dp[19][1][1];
    return res;
}

int main() {
    ll l, r;
    cin >> n >> l >> r;
    ostringstream sout;
    sout << std::setfill('0') << std::setw(19) << n;
    ns = sout.str();
    ll ans = f(r) - f(l-1);
    cout << ans << endl;
    return 0;
}