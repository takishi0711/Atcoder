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
const double PI = acos(-1);

struct edge {
    int to;
    int cost;
};

using mint = modint1000000007;

//typedef pair<int, int> P;  // first: 最短距離, second: 頂点番号

int V, d[200005];
mint cnt[200005];
vector<edge> G[200005]; // 隣接リスト表現

void dijkstra(int s) {
    //fill(d, d + V, INF);
    d[s] = 0;  // 始点sへの最短距離は0
    //fill(cnt, cnt + V, 0);
    cnt[s] = 1;  // 始点sへの最短経路数は1

    priority_queue<P, vector<P>, greater<P>> que;  // 距離が小さい順に取り出せるようgreater<P>を指定
    que.push(P(0, s));
    while (!que.empty()) {
        P p = que.top();
        que.pop();
        int v = p.second;  // 更新した頂点の中で距離が最小の頂点v
        if (d[v] < p.first) {
            continue;
        }
        for (auto e : G[v]) {  // 頂点vから出る辺eを走査
            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
                cnt[e.to] = cnt[v];  // コストが更新された場合は直前の頂点への最短経路数で上書き
            } else if (d[e.to] == d[v] + e.cost) {
                cnt[e.to] += cnt[v];  // コストが一致する場合はこれまでの最短経路数を足し合わせ
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    rep(i,m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back((edge){b,1});
        G[b].push_back((edge){a,1});
    }
    rep(i,n) d[i] = INF;
    dijkstra(0);
    cout << cnt[n-1].val() << endl;
    return 0;
}