#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y);
#define chmin(x,y) x = min(x,y);
const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, -1, 0, 1 };
const int dx[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
const int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
const int INF = 1001001001;
const ll LINF = 1001002003004005006ll;
const double PI = acos(-1);

// ABC141 F - Xor Sum 3

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    ll s = 0;
    rep(i,n) s ^= a[i];
    ll ans = s;
    rep(i,n) a[i] &= ~s;

    int r = 0;
    for (int i = 60; i >= 0; i--) {
        int j = r;
        for (; j < n; j++) {
            if (a[j]>>i&1) {
                swap(a[r], a[j]);
                break;
            }
        }
        if (j == n) continue;
        rep(k,n) {
            if (k == r) continue;
            if (a[k]>>i&1) a[k] ^= a[r];
        }
        r++;
    }

    ll ans2 = 0;
    rep(i,n) ans2 ^= a[i];
    ans += ans2*2;
    cout << ans << endl;
    return 0;
}