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
    int to, d;
};

vector<Edge> g[2005];
vector<Edge> l[2005];

vector<vector<int>> dist(2005, vector<int>(2005));

int main() {
    int n, m;
    cin >> n >> m;
    rep(i,m) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        if (a == b) {
            l[a].push_back((Edge){b,c});
            //l[b].push_back((Edge){a,c});
        } else {
            g[a].push_back((Edge){b,c});
            //g[b].push_back((Edge){a,c});
        }
    }
    rep(i,2003)rep(j,2003) dist[i][j] = INF;
    rep(i,n) {
        dist[i][i] = 0;
        priority_queue<P, vector<P>, greater<P>> q;
        q.emplace(0,i);
        while (!q.empty()) {
            int dn = q.top().first;
            int v = q.top().second;
            q.pop();
            if (dist[i][v] != dn) continue;
            rep(j,int(g[v].size())) {
                int dd = g[v][j].d;
                int u = g[v][j].to;
                if (dist[i][u] <= dn+dd) continue;
                dist[i][u] = dn+dd;
                q.emplace(dist[i][u],u);
            }
        }
    }
    rep(i,n) dist[i][i] = INF;
    rep(i,n) {
        rep(j,int(l[i].size())) {
            chmin(dist[i][i], l[i][j].d);
        }
    }
    vector<int> ans(n,INF);
    rep(i,n) {
        rep(j,n) {
            if (i == j) {
                chmin(ans[i], dist[i][j]);
            }
            else chmin(ans[i], dist[i][j]+dist[j][i]);
        }
    }
    rep(i,n) {
        if (ans[i] == INF) ans[i] = -1;
    }
    rep(i,n) cout << ans[i] << endl;
    return 0;
}