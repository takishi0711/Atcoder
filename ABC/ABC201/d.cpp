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

int h, w;
vector<string> a(2005);
int aa[2005][2005];
int dp[2005][2005];

int dfs(int i, int j) {
    if (dp[i][j] != INF) return dp[i][j];
    int res = 0;
    if (i == h-1 && j == w-1) return dp[i][j] = 0;
    if ((i+j)%2 == 0) {
        res = -INF;
        int res2 = -INF;
        if (i+1 < h) res2 = dfs(i+1,j)+aa[i+1][j];
        int res3 = -INF;
        if (j+1 < w) res3 = dfs(i,j+1)+aa[i][j+1];
        res = max(res2,res3);
    } else {
        res = INF;
        int res2 = INF;
        if (i+1 < h) res2 = dfs(i+1,j)-aa[i+1][j];
        int res3 = INF;
        if (j+1 < w) res3 = dfs(i,j+1)-aa[i][j+1];
        res = min(res2,res3);
    } 
    return dp[i][j] = res;
}

int main() {
    cin >> h >> w;
    rep(i,h) cin >> a[i];
    rep(i,h)rep(j,w) {
        if (a[i][j] == '+') aa[i][j] = 1;
        else aa[i][j] = -1;
    }
    rep(i,h)rep(j,w) dp[i][j] = INF;
    int ans = dfs(0,0);
    if (ans > 0) cout << "Takahashi" << endl;
    if (ans < 0) cout << "Aoki" << endl;
    if (ans == 0) cout << "Draw" << endl;
    return 0;
}