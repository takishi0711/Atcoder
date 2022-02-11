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

struct Edge {
    ll to, t, k;
};

vector<Edge> g[100005];

int main() {
    ll n, m, x, y;
    cin >> n >> m >> x >> y;
    x--; y--;
    rep(i,m) {
        ll a, b, t, k;
        cin >> a >> b >> t >> k;
        a--; b--;
        g[a].push_back((Edge){b,t,k});
        g[b].push_back((Edge){a,t,k});
    }
    vector<ll> dist(n,LINF);
    dist[x] = 0;
    priority_queue<P, vector<P>, greater<P>> q;
    q.emplace(0,x);
    while (!q.empty()) {
        ll d = q.top().first;
        ll v = q.top().second;
        q.pop();
        if (dist[v] != d) continue;
        rep(i,int(g[v].size())) {
            ll u = g[v][i].to;
            ll ut = g[v][i].t;
            ll uk = g[v][i].k;
            if (d%uk == 0) {
                if (dist[u] <= d+ut) continue;
                dist[u] = d+ut;
                q.emplace(dist[u],u);
            } else {
                ll nd = uk*(d/uk+1);
                if (dist[u] <= nd+ut) continue;
                dist[u] = nd+ut;
                q.emplace(dist[u],u);
            }
        }
    }
    ll ans = dist[y];
    if (ans == LINF) ans = -1;
    cout << ans << endl; 
    return 0;
}