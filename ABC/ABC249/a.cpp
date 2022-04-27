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
    int a, b, c, d, e, f, x;
    cin >> a >> b >> c >> d >> e >> f >> x;
    int tx = x;
    int d1 = 0;
    while (tx > 0) {
        if (a < tx) {
            d1 += a*b;
            tx -= a;
        } else {
            d1 += tx*b;
            tx = 0;
        }
        tx -= c;
    }
    tx = x;
    int d2 = 0;
    while (tx > 0) {
        if (d < tx) {
            d2 += d*e;
            tx -= d;
        } else {
            d2 += tx*e;
            tx = 0;
        }
        tx -= f;
    }
    if (d1 > d2) cout << "Takahashi" << endl;
    else if (d1 < d2) cout << "Aoki" << endl;
    else cout << "Draw" << endl;
    return 0;
}