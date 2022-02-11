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

//ll dp[16][16][1<<16];

int main() {
    int h, w, a, b;
    cin >> h >> w >> a >> b;
    vector<vector<vector<vector<ll>>>> dp(h+1, vector<vector<vector<ll>>>(w+1, vector<vector<ll>>(b+1, vector<ll>(1<<w,0))));
    dp[0][0][b][0] = 1;
    rep(i,h)rep(j,w) {
        rep(used,1<<w) {
            if (used & (1<<j)) {
                int next = used & ~(1<<j);
                if (j+1 < w) {
                    rep(k,b+1) dp[i][j+1][k][next] += dp[i][j][k][used];
                } else {
                    rep(k,b+1) dp[i+1][0][k][next] += dp[i][j][k][used];
                }
            } else {
                if (j+1 < w && !(used & (1<<(j+1)))) {
                    int next = used | (1<<(j+1));
                    rep(k,b+1) dp[i][j+1][k][next] += dp[i][j][k][used];
                }
                if (i+1 < h) {
                    int next = used | (1<<j);
                    if (j+1 < w) {
                        rep(k,b+1) dp[i][j+1][k][next] += dp[i][j][k][used];
                    } else {
                        rep(k,b+1) dp[i+1][0][k][next] += dp[i][j][k][used];
                    }
                }
                for (int k = 1; k <= b; k++) {
                    if (j+1 < w) dp[i][j+1][k-1][used] += dp[i][j][k][used];
                    else dp[i+1][0][k-1][used] += dp[i][j][k][used];
                }
            }
        }
    }
    cout << dp[h-1][w-1][0][(1<<w)-1] << endl;
    return 0;
}