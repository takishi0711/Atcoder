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



int main() {
    int n, m;
    cin >> n >> m;
    vector<P> edges(m);
    vector<pair<ll,int>> cost(m);
    rep(i,m) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        a--; b--;
        edges[i].first = a;
        edges[i].second = b;
        cost[i].first = c;
        cost[i].second = i;
    } 
    sort(cost.begin(), cost.end());
    dsu d(n);
    ll ans = 0;
    rep(i,m) {
        int id = cost[i].second;
        if (!d.same(edges[id].first, edges[id].second)) {
            d.merge(edges[id].first, edges[id].second);
        } else {
            if (cost[i].first > 0) ans += cost[i].first;
        }
    }
    cout << ans << endl;
    return 0;
}