#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,int>;
#define chmax(x,y) x = max(x,y);
#define chmin(x,y) x = min(x,y);
const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, -1, 0, 1 };
const int dx[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
const int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
const int INF = 1001001001;
const ll LINF = 1001002003004005006ll;
const double PI = acos(-1);

struct E {
  int u, v, cost;
};
vector<vector<E>> g;

vector<ll> dijkstra(int start = 0) {
    int N = g.size();
    vector<ll> d(N, LINF);
    using P = pair<ll, int>;
    priority_queue<P, vector<P>, greater<P>> Q;
    Q.emplace(0, start);
    d[start] = 0;
    while (!Q.empty()) {
        auto [dc, c] = Q.top();
        Q.pop();
        if (d[c] != dc) continue;
        for (auto& e : g[c]) {
            ll dist = dc + e.cost;
            if (dist < d[e.v]) {
                d[e.v] = dist;
                Q.emplace(dist, e.v);
            }
        }
    }
    return d;
}

int main() {
    
    return 0;
}