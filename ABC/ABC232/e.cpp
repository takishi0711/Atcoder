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

using mint = modint998244353;

int main() {
    ll h, w, k;
    cin >> h >> w >> k;
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if (k == 1) {
        if ((x1 == x2) && (y1 == y2)) cout << 0 << endl;
        if ((x1 == x2) || (y1 == y2)) cout << 1 << endl;
        else cout << 0 << endl;
    } else {
        mint ans;
        for (int i = 1; i <= k-1; i++) {
            mint a = h+w-2;
            mint b = h-1;
            ans += a.pow(i-1) * b.pow(k-i-1);
        }
        for (int i = 1; i <= k-1; i++) {
            mint a = h+w-2;
            mint b = w-1;
            ans += a.pow(i-1) * b.pow(k-i-1);
        }
        cout << ans.val() << endl;
    }
    return 0;
}