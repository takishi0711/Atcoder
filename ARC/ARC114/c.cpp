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

using mint = modint998244353;

mint dp[5005][5005];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) dp[0][i] = 1;
    rep(i,n) {
        for (int j = 2; j <= m; j++) {
            
        }
    }
    return 0;
}