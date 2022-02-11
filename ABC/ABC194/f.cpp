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

int f(char c) {
    if ('0' <= c && c <= '9') {
        return int(c-'0');
    } else {
        return int(c-'A') + 10;
    }
}

using mint = modint1000000007;

mint dp[200005][17][2];

int main() {
    string s;
    int k;
    cin >> s;
    cin >> k;
    int n = s.size();
    dp[0][0][0] = 1;
    rep(i,n) {
        for (int j = 1; j <= 16; j++) {
            if (j < f(s[i])+1) {
                dp[i+1][j][0] = dp[i][j-1][0];
            } else {
                dp[i+1][j][0] = dp[i][j][0];
            }
        }
        for (int j = 1; j <= 16; j++) {
            dp[i+1][j][1] = dp[i][j-1][1]*(16-j);
            dp[i+1][j][1] += dp[i][j][1];
            dp[i+1][j][0] += dp[i][j-1][0]*(16-j);
            dp[i+1][j][0] += dp[i][j][0]*j;
        }
    }
    mint ans = 0;
    ans = dp[n][k][0]+dp[n][k][1];
    cout << ans.val() << endl;
    return 0;
}