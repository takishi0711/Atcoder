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
    ll l, r;
    cin >> l >> r;
    ll mx = 0;
    for (ll i = r; i >= 0; i--) {
        if (gcd(l,i) == 1) {
            mx = max(mx,i-l);
            break;
        }
    }
    l++;
    for (ll i = r; i >= 0; i--) {
        if (gcd(l,i) == 1) {
            mx = max(mx,i-l);
            break;
        }
    }
    cout << mx << endl;
    return 0;
}