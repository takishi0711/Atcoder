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
    vector<double> a(n), b(n);
    rep(i,n) cin >> a[i] >> b[i];
    vector<double> time_left(n+1), time_right(n+1);
    double now = 0;
    rep(i,n) {
        now += a[i]/b[i];
        time_left[i+1] = now;
    }
    now = 0;
    for (int i = n-1; i >= 0; i--) {
        now += a[i]/b[i];
        time_right[i] = now;
    }
    double ans = 0;
    rep(i,n+1) {
        if (time_left[i] > time_right[i]) {
            double x = (a[i-1]/b[i-1] + time_left[i-1] + time_right[i])/2;
            ans = ans + (x - time_left[i-1])*b[i-1];
            break;
        }
        if (i > 0) ans += a[i-1];
    }
    printf("%.10f\n", ans);
    return 0;
}