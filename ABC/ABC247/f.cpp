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

using mint = modint998244353;

int main() {
    int n;
    cin >> n;
    vector<int> p(n), q(n);
    rep(i,n) {
        cin >> p[i];
        p[i]--;
    }
    rep(i,n) {
        cin >> q[i];
        q[i]--;
    }
    dsu d(n);
    rep(i,n) {
        d.merge(p[i], q[i]);
    }
    mint ans = 1;
    rep(i,n) {
        if (d.leader(i) == i) {
            mint now = 0, now2 = 0;
            int m = d.size(i);
            if (m == 1) continue;
            vector<vector<vector<mint>>> dp(m+1, vector<vector<mint>>(2, vector<mint>(2)));
            dp[1][1][1] = 1;
            dp[1][0][0] = 1;
            for (int j = 1; j < m; j++) rep(k,2) {
                dp[j+1][k][1] += dp[j][k][0]+dp[j][k][1];
                dp[j+1][k][0] += dp[j][k][1];
            }
            rep(i,2)rep(j,2) {
                if (i == 0 && j == 0) continue;
                now += dp[m][i][j];
            }
            ans *= now;
        }
    }
    cout << ans.val() << endl;
    return 0;
}