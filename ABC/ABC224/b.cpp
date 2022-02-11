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

ll a[55][55];

int main() {
    int h, w;
    cin >> h >> w;
    rep(i,h)rep(j,w) cin >> a[i][j];
    bool ok = true;
    rep(i1,h) {
        for (int i2 = i1+1; i2 < h; i2++) {
            rep(j1,w) {
                for (int j2 = j1+1; j2 < w; j2++) {
                    if (!(a[i1][j1]+a[i2][j2] <= a[i2][j1]+a[i1][j2])) ok = false;
                }
            }
        }
    }
    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}