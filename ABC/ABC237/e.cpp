#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
#define chmax(x,y) x = max(x,y);
#define chmin(x,y) x = min(x,y);
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};
const int INF = 1001001001;
const ll LINF = 1001002003004005006ll;
const double PI = acos(-1);

struct Edge {
    int to;
    ll cost;
};

vector<Edge> g[200005];

int main() {
    int n, m;
    cin >> n >> m;
    vector<ll> h(n);
    rep(i,n) cin >> h[i];
    rep(i,m) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        if (h[u] > h[v]) {
            g[u].push_back((Edge){v, h[v]-h[u]});
            g[v].push_back((Edge){u, (h[u]-h[v])*2});
        } else {
            g[u].push_back((Edge){v, (h[v]-h[u])*2});
            g[v].push_back((Edge){u, h[u]-h[v]});
        }
    }
    vector<ll> dist(n, LINF);
    dist[0] = 0;
    priority_queue<P, vector<P>, greater<P>> q;
    q.emplace(dist[0], 0);
    while (!q.empty()) {
        ll di = q.top().first;
        int id = q.top().second;
        q.pop();
        if (dist[id] != di) continue;
        rep(i,g[id].size()) {
            int to = g[id][i].to;
            ll co = g[id][i].cost;
            if (dist[to] > dist[id]+co) {
                dist[to] = dist[id]+co;
                q.emplace(dist[to], to);
            }
        } 
    }
    ll ans = 0;
    rep(i,n) {
        chmin(ans, dist[i]);
    }
    cout << -ans << endl;
    return 0; 
}