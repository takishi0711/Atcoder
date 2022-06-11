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

mint dp[1005][5005], dpsum[1005][5005];

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        dp[0][i] = 1;
        dpsum[0][i] = dpsum[0][i-1] + dp[0][i];
    }
    rep(i,n-1) {
        for (int j = 1; j <= m; j++) {
            if (k == 0) {
                dp[i+1][j] = dpsum[i][m];
                dpsum[i+1][j] = dpsum[i+1][j-1] + dp[i+1][j];
                continue;
            }
            dp[i+1][j] = dpsum[i][max(0,j-k)] + dpsum[i][m] - dpsum[i][min(m,j+k-1)];
            dpsum[i+1][j] = dpsum[i+1][j-1] + dp[i+1][j];
        }
    }
    mint ans = 0;
    for (int i = 1; i <= m; i++) ans += dp[n-1][i];
    cout << ans.val() << endl;
    return 0;
}