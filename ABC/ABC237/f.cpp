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

mint dp[1005][15][5];

int main() {
    int n, m;
    cin >> n >> m;
    rep(i,m) dp[0][i][1] = 1;
    rep(i,n-1) {
        rep(j,m) {
            for (int k = j; k < m; k++) {
                for (int l = 1; l <= 3; l++) {
                    dp[i+1][j][1] += dp[i][k][l];
                }
            }

            for (int k = 0; k < j; k++) {
                dp[i+1][j][2] += dp[i][k][1];
            }
            for (int k = j; k < m; k++) {
                for (int l = 1; l <= 3; l++) {
                    dp[i+1][j][2] += dp[i][k][l];
                }
            }

            for (int k = 0; k < j; k++) {
                dp[i+1][j][3] += dp[i][k][2];
            }
            for (int k = j; k < m; k++) {
                for (int l = 1; l <= 3; l++) {
                    dp[i+1][j][3] += dp[i][k][l];
                }
            }
        }
    }
    mint ans = 0;
    rep(i,m) ans += dp[n-1][i][3];
    cout << ans.val() << endl;
    return 0;
}