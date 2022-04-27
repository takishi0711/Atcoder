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
    dpsum[1][0] = 1;
    vector<int> ten = {0, 1, 10, 100, 1000, 10000};
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= 4; k++) {
                if (j-k-1 < 0) continue;
                int l = max(0, i-ten[k+1]+1);
                if (i-ten[k] <= 0) continue;
                int x = max(0, i-ten[k]), y = max(0, i-ten[k+1]);
                if (y) dp[i][j] += (dpsum[x][j-k-1] - dpsum[y][j-k-1]) * (j-k-1 == 0 ? 26 : 25);
                else dp[i][j] += dpsum[x][j-k-1] * (j-k-1 == 0 ? 26 : 25);
            }
            dpsum[i+1][j] = dpsum[i][j] + dp[i][j];
        }
    } 

    mint ans = 0;
    rep(i,n) ans += dp[n][i];
    cout << ans.val() << endl;
    return 0;
}