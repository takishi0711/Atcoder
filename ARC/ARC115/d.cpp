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

struct Edge {
    int to1, to2, x;
};

vector<int> to[5005];
vector<Edge> edges; 

using mint = modint998244353;

mint dp[5005][5005];

int main() {
    int n, m;
    cin >> n >> m;
    rep(i,m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        to[a].push_back(b);
        to[b].push_back(a);
        edges.push_back((Edge){a,b,0});
    }
    rep(i,m) {
        int a = edges[i].to1, b = edges[i].to2;
        int cnta = to[a].size(), cntb = to[b].size();
        if (a >= 2 && b >= 2) edges[i].x = 0;
        else if (a >= 2 || b >= 2) edges[i].x = 1;
        else edges[i].x = 2;
    }
    dp[0][0] = 1;
    rep(i,m) {
        int id = edges[i].x;
        int a = edges[i].to1, b = edges[i].to2;
        int cnta = to[a].size(), cntb = to[b].size();
        cnta; cntb;
        if (cntb == 1) swap(cnta, cntb);
        if (id == 0) {
            for (int k = 0; k <= n; k++) {
                if (k-2 >= 0) dp[i+1][k-2] += dp[i][k]*((mint)(cnta)/2)*((cntb)/2);
                dp[i+1][k] += dp[i][k]*(mint(1) + (mint)(cnta+1)/2*((cntb)/2) + (mint)(cntb+1)/2*((cnta)/2));
                dp[i+1][k+2] += dp[i][k]*((mint)(cnta+1)/2)*((cntb+1)/2);
            }
        } else if (id == 1) {
            for (int k = 0; k <= n; k++) {
                dp[i+1][k] += dp[i][k]*(mint(1) + (cntb)/2);
                dp[i+1][k+2] += dp[i][k]*(cntb+1)/2;
            }
        } else {
            for (int k = 0; k <= n; k++) {
                dp[i+1][k] += dp[i][k];
                dp[i+1][k+2] += dp[i][k];
            }
        }
    }
    for (int i = 0; i <= n; i++) {
        cout << dp[m][i].val() << endl;
    }
    return 0;
}