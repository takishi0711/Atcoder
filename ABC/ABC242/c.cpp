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

mint dp[1000005][10];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= 9; i++) dp[0][i] = 1;
    rep(i,n-1) {
        for (int j = 1; j <= 9; j++) {
            if (j == 1) {
                dp[i+1][j] += dp[i][j];
                dp[i+1][j+1] += dp[i][j];
            } else if (j == 9) {
                dp[i+1][j] += dp[i][j];
                dp[i+1][j-1] += dp[i][j];
            } else {
                dp[i+1][j+1] += dp[i][j];
                dp[i+1][j] += dp[i][j];
                dp[i+1][j-1] += dp[i][j];
            }
        }
    }
    mint ans = 0;
    for (int i = 1; i <= 9; i++) {
        ans += dp[n-1][i];
    }
    cout << ans.val() << endl;
    return 0;
}