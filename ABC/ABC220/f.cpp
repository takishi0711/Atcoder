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

vector<int> to[200005];
int cnt[200005];
ll dp[200005];
int dep[200005];
int n;

void dfs1(int v, int p=-1) {
    cnt[v] = 1;
    for (int u : to[v]) {
        if (u == p) continue;
        dep[u] = dep[v]+1;
        dfs1(u,v);
        cnt[v] += cnt[u];
    }
}

void dfs3(int v, int p=-1) {
    for (int u : to[v]) {
        if (u == p) continue;
        dp[u] += dp[v];
        dfs3(u,v);
    }
} 

int main() {
    cin >> n;
    vector<P> edges;
    rep(i,n-1) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        to[u].push_back(v);
        to[v].push_back(u);
        edges.push_back(P(u,v));
    }
    dfs1(0);
    rep(i,n-1) {
        auto [u, v] = edges[i];
        if (!(dep[u] < dep[v])) swap(u, v);
        dp[v] += n-cnt[v];
        dp[0] += cnt[v];
        dp[v] -= cnt[v];
    }
    dfs3(0);
    rep(i,n) cout << dp[i] << endl;
    return 0;
}