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



int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<int>> a(h, vector<int>(w));
    rep(i,h)rep(j,w) cin >> a[i][j];
    int mn = INF;
    rep(i,h)rep(j,w) {
        if (a[i][j] < mn) mn = a[i][j];
    }
    int ans = 0;
    rep(i,h)rep(j,w) {
        ans += a[i][j]-mn;
    }
    cout << ans << endl;
    return 0;
}