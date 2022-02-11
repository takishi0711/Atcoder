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
    int n, k;
    cin >> n >> k;
    vector<int> l(n), r(n);
    vector<bool> used(n);
    rep(i,k) {
        char c;
        int x;
        cin >> c >> x;
        x--;
        used[x] = true;
        if (c == 'L') {
            l[x]++;
        } else {
            r[x]++;
        }
    }
    for (int i = 0; i < n-1; i++) {
        l[i+1] += l[i];
    }
    for (int i = n-1; i > 0; i--) {
        r[i-1] += r[i];
    }
    vector<int> sum(n);
    rep(i,n) sum[i] = l[i]+r[i];
    mint ans = 1;
    rep(i,n) {
        if (used[i]) continue;
        ans *= sum[i];
    }
    cout << ans.val() << endl;
    return 0;
}