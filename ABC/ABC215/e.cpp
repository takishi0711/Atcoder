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

mint dp[1005][15][1<<10];

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    dp[0][10][0] = 1;
    rep(i,n) {
        int c = s[i]-'A';
        rep(si,1<<10) {
            if (!(si>>c&1)) continue;
            rep(j,11) {
                if (j == 10) {
                    dp[i+1][c][si] += dp[i][10][0];
                }
                if (!(si>>j&1)) continue;
                if (j == c) {
                    dp[i+1][c][si] += dp[i][j][si];
                } else {
                    dp[i+1][c][si] += dp[i][j][si ^ (1<<c)];
                }
            }
        }
    }
    mint ans = 0;
    rep(i,10) {
        rep(j,1<<10) ans += dp[n][i][j];
    } 
    cout << ans.val() << endl;
    return 0;
}