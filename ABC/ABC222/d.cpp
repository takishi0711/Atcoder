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

mint dp[3005][3005];

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    for (int i = a[0]; i <= b[0]; i++) dp[0][i]++;
    for (int i = 1; i <= n-1; i++) {
        for (int j = 0; j <= 3001; j++) {
            if (a[i] <= j && j <= b[i]) dp[i][j] = dp[i-1][j];
            dp[i-1][j+1] += dp[i-1][j];
        }
    }
    mint ans = 0;
    for (int i = a[n-1]; i <= b[n-1]; i++) ans += dp[n-1][i];
    cout << ans.val() << endl;
    return 0;
}