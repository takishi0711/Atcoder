#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,int>;
#define chmax(x,y) x = max(x,y);
#define chmin(x,y) x = min(x,y);
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};
const int INF = 1001001001;
const ll LINF = 1001002003004005006ll;
const double PI = acos(-1);

struct Edge {
    ll to, cost;
};

vector<Edge> g[200005];

int main() {
    int n;
    cin >> n;
    vector<ll> t(n);
    rep(i,n) {
        int k;
        cin >> t[i] >> k;
        rep(j,k) {
            int a;
            cin >> a;
            a--;
            g[i].push_back((Edge){a,t[i]});
        }
    }
    vector<ll> dist(n, LINF);
    dist[n-1] = 0;
    priority_queue<P, vector<P>, greater<P>> q;
    q.push(P(0,n-1));
    while (!q.empty()) {
        ll co = q.top().first, v = q.top().second;
        q.pop();
        if (dist[v] != co) continue;
        for (auto e : g[v]) {
            int u = e.to;
            if (dist[v]+e.cost < dist[u]) {
                dist[u] = dist[v]+e.cost;
                q.push(P(dist[u], u));
            }
        }
    }
    ll ans = LINF;
    rep(i,n) {
        if (g[i].size() == 0) {
            ans = min(ans, dist[i]+t[i]);
        }
    }
    cout << ans << endl;
    return 0;
}