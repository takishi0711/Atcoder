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
    int to, l;
};

vector<Edge> g[305];
vector<Edge> g_zero;

int main() {
    int n, m;
    cin >> n >> m;
    rep(i,m) {
        int u, v, l;
        cin >> u >> v >> l;
        u--; v--;
        if (u == 0) {
            g_zero.push_back((Edge){v,l});
        } else {
            g[u].push_back((Edge){v,l});
            g[v].push_back((Edge){u,l});
        }
    }
    // 全ての始点からダイクストラ
    vector<vector<int>> dist(n, vector<int>(n,INF));
    rep(si,n) {
        if (si == 0) continue;
        dist[si][si] = 0;
        priority_queue<P, vector<P>, greater<P>> q;
        q.emplace(0,si);
        while (!q.empty()) {
            int d = q.top().first;
            int v = q.top().second;
            q.pop();
            if (dist[si][v] != d) continue;
            rep(i,g[v].size()) {
                int l = g[v][i].l;
                int u = g[v][i].to;
                if (dist[si][u] <= d+l) continue;
                dist[si][u] = d+l;
                q.emplace(dist[si][u],u);
            }
        }
    }
    int ans = INF;
    rep(i,g_zero.size()) for (int j = i+1; j < g_zero.size(); j++) {
        int v1 = g_zero[i].to, v2 = g_zero[j].to;
        int l1 = g_zero[i].l, l2 = g_zero[j].l;
        if (dist[v1][v2] == INF) continue;
        ans = min(ans, l1+l2+dist[v1][v2]);
    }
    if (ans == INF) ans = -1;
    cout << ans << endl;
    return 0;
}