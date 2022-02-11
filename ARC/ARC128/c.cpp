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
    ll n, m, s; // m = 最大, s = 総和
    cin >> n >> m >> s;
    vector<double> a(n);
    rep(i,n) cin >> a[i];
    double ans = 0;
    // 後ろから最大入れていく
    ll now_s = s; // 残り
    double score = 0;
    for (int i = n-1; i >= 0; i--) {
        if (now_s >= m) {
            score += a[i]*m;
            now_s -= m;
        } else {
            score += a[i]*now_s;
            break;
        }
    }
    ans = max(ans, score);
    // 使う数決め打ち
    for (int x = 1; x <= n; x++) {
        if (s > m*x) continue;
        score = 0;
        for (int i = n-1; i > n-1-x; i--) {
            score += a[i]*(double)s/x;
        }
        ans = max(ans, score);
    }

    printf("%.10f\n", ans);
    return 0;
}