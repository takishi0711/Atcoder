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
    int n;
    cin >> n;
    vector<bool> ok(100005,true);
    rep(is,1<<6) {
        ll ten = 0, eight = 0;
        int a = 1, b = 1;
        rep(i,6) {
            if (is>>i&1) {
                ten += 7*a;
                eight += 7*b;
            }
            a *= 10;
            b *= 8;
        }
        if (ten <= 100000) ok[ten] = false;
        if (eight <= 100000) ok[eight] = false;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (ok[i]) ans++;
    }
    cout << ans << endl;
    return 0;
}