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
mint dp[5005][5005];
mint dpsum[5005];

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<bool>> no(n+1, vector<bool>(n+1));
    vector<vector<int>> to(n+1);
    rep(i,m) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        no[u][v] = true;
        no[v][u] = true;
        to[u].push_back(v);
        to[v].push_back(u);
    }
    dp[0][0] = 1;
    dpsum[0] = 1;
    rep(i,n) {
        rep(j,n) {
            dp[i+1][j] += dpsum[i];
            dp[i+1][j] -= dp[i][j];
            for (int x : to[j]) {
                dp[i+1][j] -= dp[i][x];
            }
            dpsum[i+1] += dp[i+1][j];
        }
    }
    cout << dp[k][0].val() << endl;
    return 0;
}