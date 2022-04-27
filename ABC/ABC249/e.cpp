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

using mint = modint;

mint dp[3005][3005], dpsum[3005][3005];

int main() {
    int n, p;
    cin >> n >> p;
    mint::set_mod(p);

    dp[0][0] = 1;
    dpsum[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 2; j <= n; j++) {
            if (1 <= i && i <= 9) {
                dp[i][j] += dpsum[i-1][j-2]*(j-2 == 0 ? 26 : 25);
            } else if (10 <= i && i <= 99) {
                dp[i][j] += (dpsum[i-1][j-2]-dpsum[i-10][j-2])*(j-2 == 0 ? 26 : 25);
                if (j-3 >= 0) dp[i][j] += dpsum[i-10][j-3]*(j-3 == 0 ? 26 : 25);
            } else if (100 <= i && i <= 999) {
                dp[i][j] += (dpsum[i-1][j-2]-dpsum[i-10][j-2])*(j-2 == 0 ? 26 : 25);
                if (j-3 >= 0) dp[i][j] += (dpsum[i-10][j-3]-dpsum[i-100][j-3])*(j-3 == 0 ? 26 : 25);
                if (j-4 >= 0) dp[i][j] += dpsum[i-100][j-4]*(j-4 == 0 ? 26 : 25);
            } else {
                dp[i][j] += (dpsum[i-1][j-2]-dpsum[i-10][j-2])*(j-2 == 0 ? 26 : 25);
                if (j-3 >= 0) dp[i][j] += (dpsum[i-10][j-3]-dpsum[i-100][j-3])*(j-3 == 0 ? 26 : 25);
                if (j-4 >= 0) dp[i][j] += (dpsum[i-100][j-4]-dpsum[i-1000][j-4])*(j-4 == 0 ? 26 : 25);
                if (j-5 >= 0) dp[i][j] += dpsum[i-1000][j-5]*(j-5 == 0 ? 26 : 25);
            }
        }
        for (int j = 0; j <= n; j++) {
            dpsum[i][j] = dpsum[i-1][j] + dp[i][j];
        }
    } 

    mint ans = 0;
    rep(i,n) ans += dp[n][i];
    cout << ans.val() << endl;
    return 0;
}