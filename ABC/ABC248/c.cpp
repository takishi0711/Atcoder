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

mint dp[55][2505];

int main() {
    int n, m, K;
    cin >> n >> m >> K;
    dp[0][0] = 1;
    rep(i,n) {
        for (int j = 1; j <= m; j++) {
            for (int k = 0; k <= K; k++) {
                if (k-j >= 0) {
                    dp[i+1][k] += dp[i][k-j];
                }
            }
        }
    }
    mint ans = 0;
    for (int i = 0; i <= K; i++) ans += dp[n][i];
    cout << ans.val() << endl;
    return 0;
}