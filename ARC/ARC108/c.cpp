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
    int to, rab;
};

int n;
vector<vector<Edge>> g;
vector<int> ans;

void dfs(int v, int p=-1) {
    rep(i,g[v].size()) {
        int u = g[v][i].to, x = g[v][i].rab;
        if (u == p) continue;
        if (ans[u] != -1) continue;
        if (ans[v] == x) {
            if (x > 1) ans[u] = x-1;
            else if (x < n-1) ans[u] = x+1;
        } else {
            ans[u] = x;
        }
        dfs(u,v);
    }
}

int main() {
    int m;
    cin >> n >> m;
    g.resize(n);
    ans = vector<int>(n, -1);
    rep(i,m) {
        int u, v, c;
        cin >> u >> v >> c;
        u--; v--; c--;
        g[u].push_back((Edge){v,c});
        g[v].push_back((Edge){u,c});
    }
    ans[0] = g[0][0].rab;
    dfs(0);
    dsu d(n);
    rep(i,n) {
        for (auto e : g[i]) {
            int u = e.to;
            int x = e.rab;
            if (ans[i] == x && ans[u] == x) continue;
            if (ans[i] != x && ans[u] != x) continue;
            d.merge(i,u);
        }
    }
    if (d.size(0) != n)  {
        cout << "No" << endl;
        return 0;
    }
    rep(i,n) {
        cout << ans[i]+1 << endl;
    }
    return 0;
}