#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
#define chmax(x,y) x = max(x,y);
#define chmin(x,y) x = min(x,y);
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};
const int INF = 1001001001;
const ll LINF = 1001002003004005006ll;
const double PI = acos(-1);



int main() {
    int n;
    ll w;
    cin >> n >> w;
    vector<P> ab(n);
    rep(i,n) cin >> ab[i].first >> ab[i].second;
    sort(ab.rbegin(), ab.rend());
    ll ans = 0;
    rep(i,n) {
        if (w-ab[i].second < 0) {
            ans += ab[i].first * (w);
            break;
        }
        ans += ab[i].first * ab[i].second;
        w -= ab[i].second;
    }
    cout << ans << endl;
    return 0;
}