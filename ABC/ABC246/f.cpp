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

using mint = modint998244353;

int main() {
    int n, l;
    cin >> n >> l;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    vector<int> bi(n);
    rep(i,n) {
        for (char c : s[i]) {
            bi[i] |= 1<<(c-'a');
        }
    }
    mint ans = 0;
    rep(si,1<<n) {
        if (si == 0) continue;
        int cnt = __builtin_popcount(si);

        int xsum = (1<<26)-1;
        rep(i,n) {
            if (si>>i&1) {
                xsum &= bi[i];
            }
        }

        int cnt2 = __builtin_popcount(xsum);
        mint now = mint(cnt2).pow(l);
        if (cnt%2) ans += now;
        else ans -= now;
    }
    cout << ans.val() << endl;
    return 0;
}