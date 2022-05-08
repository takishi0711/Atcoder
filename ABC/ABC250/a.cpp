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
    int h, w;
    cin >> h >> w;
    int r, c;
    cin >> r >> c;
    r--; c--;
    if (h < r || w < c) {
        cout << 0 << endl;
        return 0;
    }
    int ans = 4;
    if (r == 0) ans--;
    if (r == h-1) ans--;
    if (c == 0) ans--;
    if (c == w-1) ans--;
    cout << ans << endl;
    return 0;
}