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

vector<int> to[1005];

using mint = modint998244353;

mint dp[1005][100005];

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(m);
    rep(i,m) {
        cin >> a[i];
        a[i]--;
    }
    map<P, int> mp;
    rep(i,n-1) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        to[u].push_back(v);
        to[v].push_back(u);
        mp[P(u,v)] = i;
        mp[P(v,u)] = i;
    }
    vector<vector<int>> dist(n, vector<int>(n, INF));
    rep(i,n) {
        dist[i][i] = 0;
        queue<int> q;
        q.push(i);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int u : to[v]) {
                if (dist[i][u] != INF) continue;
                dist[i][u] = dist[i][v]+1;
                q.push(u);
            }
        }
    }
    vector<int> ed(n-1);
    rep(i,m-1) {
        int now = a[i], end = a[i+1];
        while (now != end) {
            for (int nex : to[now]) {
                if (dist[end][nex] < dist[end][now]) {
                    ed[mp[P(now,nex)]]++;
                    now = nex;
                    break;
                }
            }
        }
    }
    int sum = 0;
    rep(i,n-1) sum += ed[i];
    dp[0][0] = 1;
    rep(i,n-1) {
        for (int j = 0; j <= sum; j++) {
            if (j-ed[i] >= 0) dp[i+1][j] += dp[i][j-ed[i]];
            dp[i+1][j] += dp[i][j];
        }
    }
    if (k+sum < 0) {
        cout << 0 << endl;
    } else if ((k+sum)%2 != 0) {
        cout << 0 << endl;
    } else {
        cout << dp[n-1][(k+sum)/2].val() << endl;
    }
    return 0;
}