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
    int n, w;
    cin >> n >> w;
    vector<int> a(n+1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    mf_graph<int> g(n+2);
    for (int i = 1; i <= n; i++) {
        g.add_edge(0, i, w);
        g.add_edge(i, n+1, a[i]);
    }
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        for (int j = 1; j <= k; j++) {
            int c;
            cin >> c;
            g.add_edge(i, c, INF);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) ans += a[i];
    ans -= g.flow(0,n+1);
    cout << ans << endl;
    return 0;
}