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
    int t;
    cin >> t;
    rep(ti,t) {
        ll n2, n3, n4;
        cin >> n2 >> n3 >> n4;
        ll ans = 0;
        ll num3 = n3/2;
        if (num3 <= n4) {
            ans += num3;
            n4 -= num3;
            ll num4 = n4/2;
            if (num4 <= n2) {
                ans += num4;
                n2 -= num4;
                if (n4%2 == 1) n2 += 2;
                ans += n2/5;
            } else {
                ans += n2;
            }
        } else {
            ans += n4;
            num3 -= n4;
            ll num2 = n2/2;
            if (num2 <= num3) {
                ans += num2;
            } else {
                ans += num3;
                n2 -= num3*2;
                ans += n2/5;
            }
        }
        cout << ans << endl;
    }
    return 0;
}