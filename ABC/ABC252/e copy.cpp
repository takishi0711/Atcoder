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

int main() {
    int n, m;
    cin >> n >> m;
    vector<ll> a(m), b(m), c(m);
    rep(i,m) {
        cin >> a[i] >> b[i] >> c[i];
        a[i]--; b[i]--;
        to[a[i]].push_back(make_tuple(c[i], b[i], i));
        to[b[i]].push_back(make_tuple(c[i], a[i], i));
    }
    vector<int> ans;
    priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, greater<tuple<ll, ll, ll>>> q;
    for (auto tp : to[0]) {
        q.push(tp);
    }
    vector<bool> used(n);
    vector<ll> dist(n, LINF);
    dist[0] = 0; 
    used[0] = true;
    while (!q.empty()) {
        int v = get<1>(q.top());
        int id = get<2>(q.top());
        q.pop();
        if (used[v]) continue;
        used[v] = true;
        ans.push_back(id);
        for (auto tp : to[v]) {
            int u = get<1>(tp);
            if (used[u]) continue;
            q.push(tp);
        }
    }

    rep(i,n-1) {
        if (i == n-1-1) cout << ans[i]+1 << endl;
        else cout << ans[i]+1 << " ";
    }
    return 0;
}