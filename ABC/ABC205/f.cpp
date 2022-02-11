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
    int h, w, n;
    cin >> h >> w >> n;
    mf_graph<int> g1(n+h+5), g2(n+w+5);
    for (int i = 1; i <= n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        g1.add_edge(0, i, 1);
        g2.add_edge(0, i, 1);
        for (int j = a; j <= c; j++) {
            g1.add_edge(i, j, 1);
        }
        for (int j = b; j <= d; j++) {
            g2.add_edge(i, j, 1);
        }
    }
    for (int i = n+1; i <= n+h; i++) {
        g1.add_edge(i, n+h+1, 1);
    }
    for (int i = n+1; i <= n+w; i++) {
        g2.add_edge(i, n+w+1, 1);
    }
    int ans = max(g1.flow(0,n+h+1), g1.flow(0,n+w+1));
    cout << ans << endl;
    return 0;
}