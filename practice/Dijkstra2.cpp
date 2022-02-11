#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y);
#define chmin(x,y) x = min(x,y);
const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, -1, 0, 1 };
const int dx[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
const int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
const int INF = 1001001001;
const ll LINF = 1001002003004005006ll;
const double PI = acos(-1);

int n, m;
ll dist[100005];

struct Edge {
    int to;
    ll cost;
};

vector<Edge> to[100005];

void dijkstra(int stt) {
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> Q;
    rep(i,n) dist[i] = LINF;
    dist[stt] = 0;
    Q.push(make_pair(0,stt));

    while (!Q.empty()) {
        int pos = Q.top().second;
        ll d = Q.top().first;
        Q.pop();
        if (d != dist[pos]) continue;
        for (auto p : to[pos]) {
            int to = p.to;
            ll cost = p.cost;
            if (dist[to] > d+cost) {
                dist[to] = d+cost;
                Q.push(make_pair(dist[to], to));
            }
        }
    }
}

int main() {
    cin >> n >> m;
    rep(i,m) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        to[a].push_back((Edge){b,c});
        to[b].push_back((Edge){a,c});
    }

    vector<ll> dist0(n), distn(n);
    dijkstra(0);
    rep(i,n) dist0[i] = dist[i];
    dijkstra(n-1);
    rep(i,n) distn[i] = dist[i];

    rep(i,n) {
        cout << dist0[i]+distn[i] << endl;
    }
    return 0;
}