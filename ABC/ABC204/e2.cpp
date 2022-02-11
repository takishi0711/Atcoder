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
    int to;
    ll cost, D, left;
};

vector<Edge> g[100005];

int main() {
    int n, m;
    cin >> n >> m;
    rep(i,m) {
        int a, b;
        ll c, d;
        cin >> a >> b >> c >> d;
        a--; b--;
        ll l = 0, r = 1000000000;
        while (l+1 < r) {
            ll mid = (l+r)/2;
            if (mid*(mid+1) <= d) l = mid;
            else r = mid;
        }
        g[a].push_back((Edge){b,c,d,l});
        g[b].push_back((Edge){a,c,d,l});
    }
    vector<ll> dist(n,LINF);
    dist[0] = 0;
    priority_queue<P, vector<P>, greater<P>> q;
    q.push(P(dist[0],0));
    while (!q.empty()) {
        int v = q.top().second;
        ll di = q.top().first;
        q.pop();
        if (dist[v] != di) continue;
        rep(i,g[v].size()) {
            int u = g[v][i].to;
            ll co = g[v][i].cost;
            ll Di = g[v][i].D;
            ll lef = g[v][i].left;
            ll now = dist[v];
            if (now <= lef) {
                now = lef;
            } 
            ll kurabe = now + co + Di/(now+1);
            if (dist[u] <= kurabe) continue;
            dist[u] = kurabe;
            q.push(P(dist[u],u));
        }
    }
    ll ans = dist[n-1];
    if (ans == LINF) ans = -1;
    cout << ans << endl;
    return 0;
}