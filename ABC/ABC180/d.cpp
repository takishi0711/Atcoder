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



int main() {
    ll x, y, a, b;
    cin >> x >> y >> a >> b;
    ll ans = 0;
    while (x < y) {
        if (double(x)/10e9*a < double(x+b)/10e9) {
            ll xb = x;
            x *= a;
            if (x >= y || xb > x) break;
            ans++;
        }
        else {
            ans += (y-1-x)/b;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}