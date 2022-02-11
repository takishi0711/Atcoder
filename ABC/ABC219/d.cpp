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

int dp[305][305][305];

int main() {
    int n;
    cin >> n;
    int x, y;
    cin >> x >> y;
    vector<int> a(n), b(n);
    rep(i,n) cin >> a[i] >> b[i];
    rep(i,302)rep(j,302)rep(k,302) dp[i][j][k] = INF;
    dp[0][0][0] = 0;
    rep(i,n) {
        rep(j,x+1)rep(k,y+1) {
            chmin(dp[i+1][j][k], dp[i][j][k]);
            chmin(dp[i+1][min(j+a[i], x)][min(k+b[i], y)], dp[i][j][k]+1);
        }
    }
    if (dp[n][x][y] == INF) dp[n][x][y] = -1;
    cout << dp[n][x][y] << endl;
    return 0;
}