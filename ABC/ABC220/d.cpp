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

mint dp[100005][10];

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    dp[0][a[0]] = 1;
    for (int i = 1; i < n; i++) {
        rep(j,10) {
            dp[i][(a[i]+j)%10] += dp[i-1][j];
            dp[i][(a[i]*j)%10] += dp[i-1][j];
        }
    }
    rep(i,10) cout << dp[n-1][i].val() << endl;
    return 0;
}