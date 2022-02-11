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

mint dp[1000005][2][2];

int main() {
    ll h, w, k;
    cin >> h >> w >> k;
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    dp[0][0][0] = 1;
    rep(i,k) {
        dp[i+1][0][0] += dp[i][1][0] + dp[i][0][1];
        dp[i+1][1][0] += dp[i][0][0]*(h-1) + dp[i][1][0]*(h-2) + dp[i][1][1];
        dp[i+1][0][1] += dp[i][0][0]*(w-1) + dp[i][0][1]*(w-2) + dp[i][1][1];
        dp[i+1][1][1] += dp[i][1][0]*(w-1) + dp[i][0][1]*(h-1) + dp[i][1][1]*(h+w-4);
    }
    if (x1 == x2 && y1 == y2) {
        cout << dp[k][0][0].val() << endl;
    } else if (x1 == x2) {
        cout << (dp[k][0][1]/(w-1)).val() << endl;
    } else if (y1 == y2) {
        cout << (dp[k][1][0]/(h-1)).val() << endl;
    } else {
        ll cnt = h*w-h-w+1;
        cout << (dp[k][1][1]/cnt).val() << endl;
    }

    // rep(i,k+1) {
    //     cout << dp[i][0][0].val() << " " << dp[i][0][1].val() << " " << dp[i][1][0].val() << " " << dp[i][1][1].val() << endl;
    // }
    return 0;
}