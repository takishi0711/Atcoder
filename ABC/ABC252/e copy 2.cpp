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

vector<tuple<ll, ll, ll>> to[200005];

struct E {
  int to, cost, id;
};

vector<E> g[200005];

int main() {
    int n, m;
    cin >> n >> m;
    vector<ll> a(m), b(m), c(m);
    rep(i,m) {
        cin >> a[i] >> b[i] >> c[i];
        a[i]--; b[i]--;
        to[a[i]].push_back(make_tuple(c[i], b[i], i));
        to[b[i]].push_back(make_tuple(c[i], a[i], i));
        g[a[i]].push_back((E){b[i], c[i], i});
        g[b[i]].push_back((E){a[i], c[i], i});
    }
    vector<int> ans;
    priority_queue<P, vector<P>, greater<P>> q;
    vector<bool> used(n);
    vector<ll> dist(n, LINF);
    dist[0] = 0; 
    used[0] = true;
    q.emplace(0, 0);
    while (!q.empty()) {
        ll dis = q.top().first;
        ll v = q.top().second;
        q.pop();
        if (dist[v] != dis) continue;
        for (auto e : g[v]) {
            int u = e.to;
            if (dist[u] > dis + e.cost) {
                dist[u] = dis + e.cost;
                q.emplace(dist[u], u);
            }
        }
    }

    dsu d(n);

    queue<int> q2;
    q2.push(0);
    while (!q2.empty()) {
        int v = q2.front();
        q2.pop();
        for (auto e : g[v]) {
            int u = e.to;
            if (d.same(u,v)) continue;
            if (dist[u] == dist[v] + e.cost) {
                ans.push_back(e.id);
                d.merge(u,v);
                q2.push(u);
            }
        }
    }

    rep(i,n-1) {
        if (i == n-1-1) cout << ans[i]+1 << endl;
        else cout << ans[i]+1 << " ";
    }
    return 0;
}