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

using mint = modint1000000007;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    sort(a.begin(), a.end());
    vector<ll> sub;
    sub.push_back(a[0]);
    rep(i,n-1) {
        if (abs(a[i]-a[i+1]) == 0) continue;
        sub.push_back(abs(a[i]-a[i+1]));
    }
    mint ans = 1;
    rep(i,sub.size()) {
        ans *= sub[i]+1;
    }
    cout << ans.val() << endl;
    return 0;
}