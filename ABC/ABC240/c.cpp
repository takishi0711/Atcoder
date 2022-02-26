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

bool dp[105][10005];

int main() {
    int n;
    cin >> n;
    int x;
    cin >> x;
    vector<int> a(n), b(n);
    rep(i,n) cin >> a[i] >> b[i];
    dp[0][0] = true;
    rep(i,n) {
        rep(j,x+1) {
            if (j-a[i] >= 0) dp[i+1][j] |= dp[i][j-a[i]];
            if (j-b[i] >= 0) dp[i+1][j] |= dp[i][j-b[i]];
        }
    }
    if (dp[n][x]) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}