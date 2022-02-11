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
    cin >> n;
    vector<ll> x(n), y(n);
    rep(i,n) cin >> x[i] >> y[i];
    vector<pair<P, P>> hu(n);
    rep(i,n) {
        hu[i].first.first = x[i]-1;
        hu[i].first.second = y[i];
        hu[i].second.first = x[i];
        hu[i].second.second = y[i]-1;
    }
    sort(hu.begin(), hu.end(), [&](pair<P, P> a, pair<P, P> b) {
        if (a.first.second*b.first.first < b.first.second*a.first.first) {
            return true;
        } else {
            return false;
        }
    });
    int ans = 0;
    P now(1,0);
    rep(i,n) {
        if (now.second*hu[i].second.first <= hu[i].second.second*now.first) {
            ans++;
            now = hu[i].first;
        }
    }
    cout << ans << endl;
    return 0;
}