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
    ll n, a, b;
    cin >> n >> a >> b;
    ll p, q, r, s;
    cin >> p >> q >> r >> s;
    for (ll x = p; x <= q; x++) {
        for (ll y = r; y <= s; y++) {
            if (x-a == y-b) {
                ll k = x-a;
                if (max(1-a, 1-b) <= k && k <= min(n-a, n-b)) {
                    cout << '#';
                } else {
                    cout << '.';
                }
            } else if (x-a == b-y) {
                ll k = x-a;
                if (max(1-a, b-n) <= k && k <= min(n-a, b-1)) {
                    cout << '#';
                } else {
                    cout << '.';
                }
            } else {
                cout << '.';
            }
        }
        cout << endl;
    }
    return 0;
}