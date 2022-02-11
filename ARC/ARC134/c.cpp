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

mint choose (int n, int a) {
    mint x = 1, y = 1;
    rep(i,a) {
        x *= n-i;
        y *= i+1;
    }
    return x / y;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    ll sum = 0;
    for (int i = 1; i < n; i++) sum += a[i];
    ll sub = a[0] - sum;
    if (sub < k) {
        cout << 0 << endl;
        return 0;
    }
    mint ans = 1;
    for (int i = 1; i < n; i++) {
        ans *= choose(a[i]+k-1, k-1);
    }
    ans *= choose(sub-k+k-1, k-1);
    cout << ans.val() << endl;
    return 0;
}