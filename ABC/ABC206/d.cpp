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
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    dsu d(200005);
    int l = 0, r = n-1;
    while (l < r) {
        if (a[l] != a[r]) d.merge(a[l],a[r]);
        l++; r--;
    }
    int ans = 0;
    for (int i = 0; i <= 200000; i++) {
        if (d.leader(i) == i) {
            ans += d.size(i)-1;
        }
    }
    cout << ans << endl;
    return 0;
}