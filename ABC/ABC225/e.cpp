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
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    rep(i,n) cin >> x[i] >> y[i];
    vector<pair<double, double>> hu(n);
    rep(i,n) {
        double b = atan2(y[i], x[i]-1);
        double a = atan2(y[i]-1, x[i]);
        hu[i].first = b;
        hu[i].second = a;
    }
    sort(hu.begin(), hu.end());
    int ans = 0;
    double now = 0;
    rep(i,n) {
        if (hu[i].second >= now) {
            ans++;
            now = hu[i].first;
        }
    }
    cout << ans << endl;
    return 0;
}