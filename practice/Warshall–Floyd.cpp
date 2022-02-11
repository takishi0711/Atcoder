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
    vector<vector<int>> dist(n, vector<int>(n,INF));
    rep(i,n) dist[i][i] = 0;
    rep(i,m) {
        int u, v, l;
        cin >> u >> v >> l;
        u--; v--;
        if (u == 0) {
            g_zero.push_back((Edge){v,l});
        } else {
            g[u].push_back((Edge){v,l});
            g[v].push_back((Edge){u,l});
            dist[u][v] = l;
            dist[v][u] = l;
        }
    }

    // ワ―シャルフロイド法
    /*
    rep(k,n)rep(i,n)rep(j,n) {
        dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
    }
    */
    for (int k = 1; k < n; k++) {
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < n; j ++) {
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
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