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

bool dp[200005][2];

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> a(2, vector<int>(n));
    rep(i,2)rep(j,n) cin >> a[i][j];
    dp[0][0] = dp[0][1] = true;
    for (int i = 1; i < n; i++) {
        rep(j1,2)rep(j2,2) {
            if (dp[i-1][j1] == false) continue;
            if (abs(a[j1][i-1]-a[j2][i]) <= k) {
                dp[i][j2] = true;
            }
        }
    }
    if (dp[n-1][0] || dp[n-1][1]) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}