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

struct Edge {
    int to, cost;
};

int dp[200005];

vector<Edge> g[200005];

void dfs(int v, int p) {
    for (auto e : g[v]) {
        int u = e.to;
        int co = e.cost;
        if (u == p) continue;
        dp[u] = max(dp[v], co);
        dfs(u,v);
    }
}

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<pair<int, P>> edges;
    rep(i,m) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        edges.emplace_back(c, P(a, b));
    }
    sort(edges.begin(), edges.end());
    dsu d(n);
    map<P,int> mp;
    rep(i,m) {
        int a, b, c;
        a = edges[i].second.first;
        b = edges[i].second.second;
        c = edges[i].first;
        if (d.same(a,b)) continue;
        d.merge(a, b);
        g[a].push_back((Edge){b,c});
        g[b].push_back((Edge){a,c});
        mp[P(a,b)] = c;
        mp[P(b,a)] = c;
    }
    rep(i,n) dp[i] = 0;
    dfs(0,-1);
    rep(qi,q) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        if (u == v) cout << "No" << endl;
        else if (mp[P(u,v)] != 0) {
            if (mp[P(u,v)] < w) cout << "No" << endl;
            else cout << "Yes" << endl;
        } else {
            int tm = 0;
            chmax(tm, dp[u]);
            chmax(tm, dp[v]);
            if (tm < w) cout << "No" << endl;
            else cout << "Yes" << endl;
        }
    }
    rep(i,n) cout << dp[i] << endl;
    return 0;
}