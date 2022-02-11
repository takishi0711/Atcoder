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

using mint = modint1000000007;

int main() {
    int n;
    cin >> n;
    vector<int> c(n);
    rep(i,n) cin >> c[i];
    sort(c.begin(), c.end());
    mint ans = 1;
    rep(i,n) {
        ans *= max(0, c[i]-i);
    }
    cout << ans.val() << endl;
    return 0;
}