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
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll sum = 0;
    rep(i,n) {
        cin >> a[i];
        sum += a[i];
    }
    ll x;
    cin >> x;
    ll ans = 0;
    ans += n*(x/sum);
    x -= sum*(x/sum);
    rep(i,n) {
        if (x < 0) {
            cout << ans << endl;
            return 0;
        }
        ans++;
        x -= a[i];
    }
    if (x < 0) {
        cout << ans << endl;
        return 0;
    }
    return 0;
}