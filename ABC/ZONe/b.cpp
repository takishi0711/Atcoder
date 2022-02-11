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



int main() {
    int n, D, H;
    cin >> n >> D >> H;
    double ans = 100000;
    rep(i,n) {
        int d, h;
        cin >> d >> h;
        double now = (double)H-(double)D*(H-h)/(D-d);
        ans = max(ans, now);
    }
    if (ans < 0.0) ans = 0.0;
    printf("%.10f\n", ans);
    return 0;
}