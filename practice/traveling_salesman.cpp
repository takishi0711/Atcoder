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



int main() {
    int n;
    cin >> n;
    vector<int> x(n), y(n), z(n);
    rep(i,n) cin >> x[i] >> y[i] >> z[i];
    int n2 = 1<<n;
    vector<vector<int>> dp(n2, vector<int>(n,INF));
    vector<vector<int>> dist(n, vector<int>(n));
    rep(i,n)rep(j,n) {
        int now = abs(x[i]-x[j]);
        now += abs(y[i]-y[j]);
        now += max(0,z[j]-z[i]);
        dist[i][j] = now;
    }
    rep(i,n) {
        if (i == 0) continue;
        dp[1<<i][i] = dist[0][i];
    }
    rep(i,n2)rep(j,n) {
        if (~i>>j&1) continue;
        rep(k,n) {
            if (i>>k&1) continue;
            chmin(dp[i|1<<k][k], dp[i][j]+dist[j][k]);
        }
    }
    cout << dp[n2-1][0] << endl;
    return 0;
}