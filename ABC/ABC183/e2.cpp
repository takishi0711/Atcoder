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

using mint = modint1000000007;
vector<string> s;
bool visited[2005][2005];
mint memo[2005][2005];
mint dp[2005][2005];
mint dpsumh[2005][2005];
mint dpsumw[2005][2005];
mint dpsumhw[2005][2005];

mint f(int i, int j) {
    if (i<0||j<0) return 0;
    if (s[i][j] == '#') return 0;
    if (visited[i][j]) return memo[i][j];
    visited[i][j] = true;
    return memo[i][j] = f(i-1,j) + f(i,j-1) + f(i-1, j-1);
}

int main() {
    int h, w;
    cin >> h >> w;
    s = vector<string>(h);
    rep(i,h) cin >> s[i];
    dp[0][0] = 1; dpsumh[0][0] = 1; dpsumw[0][0] = 1; dpsumhw[0][0] = 1;
    rep(i,h)rep(j,w) {
        if (s[i][j] == '#') continue;
        if (i == 0 && j == 0) continue;
        else if (i == 0) {
            dp[i][j] = dpsumh[i][j-1];
            dpsumh[i][j] = dpsumh[i][j-1]+dp[i][j];
            dpsumw[i][j] = dp[i][j];
            dpsumhw[i][j] = dp[i][j];
        }
        else if (j == 0) {
            dp[i][j] = dpsumw[i-1][j];
            dpsumh[i][j] = dp[i][j];
            dpsumw[i][j] = dpsumw[i-1][j]+dp[i][j];
            dpsumhw[i][j] = dp[i][j];
        }
        else {
            dp[i][j] = dpsumh[i][j-1]+dpsumw[i-1][j]+dpsumhw[i-1][j-1];
            dpsumh[i][j] = dpsumh[i][j-1]+dp[i][j];
            dpsumw[i][j] = dpsumw[i-1][j]+dp[i][j];
            dpsumhw[i][j] = dpsumhw[i-1][j-1]+dp[i][j];
        }
    }
    cout << dp[h-1][w-1].val() << endl;
    return 0;
}