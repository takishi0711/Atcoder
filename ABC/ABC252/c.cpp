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
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    int ans = INF;
    for (int i = 0; i <= 9; i++) {
        vector<int> cnt(10);
        rep(j,n) {
            rep(k,10) {
                if (s[j][k] == '0' + i) {
                    cnt[k]++;
                    break;
                }
            }
        }
        int ma = 0;
        int idx_mi = 0, idx_ma = 0;
        for (int j = 0; j <= 9; j++) {
            if (cnt[j] == 0) continue;
            idx_ma = j;
            if (cnt[j] >= ma) {
                ma = cnt[j];
                idx_mi = j;
            }
        }
        if (ma == 1) {
            chmin(ans, idx_ma);
        } else {
            chmin(ans, 10*(ma-1) + idx_mi);
        }
    }
    cout << ans << endl;
    return 0;
}