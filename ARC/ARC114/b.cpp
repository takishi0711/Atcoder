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

using mint = modint998244353;

int main() {
    int n;
    cin >> n;
    vector<int> x(n);
    rep(i,n) {
        cin >> x[i];
        x[i]--;
    }
    dsu d(n);
    rep(i,n) {
        int next = x[i];
        if (d.same(i,x[i])) continue;
        else {
            int j = i;
            while (!d.same(j,x[j])) {
                d.merge(j,x[j]);
                j = x[j];
            }
        }
    }
    int cnt = 0;
    rep(i,n) {
        if (d.leader(i) == i) cnt++;
    }
    mint ans = mint(2).pow(cnt);
    ans--;
    cout << ans.val() << endl;
    return 0;
}