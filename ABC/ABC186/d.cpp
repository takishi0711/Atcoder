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
    vector<ll> a(n);
    vector<ll> b(n);
    rep(i,n) cin >> a[i];
    sort(a.begin(), a.end());
    for (int i = 1; i <= n-1; i++) {
        b[i] = a[i]-a[0];
    }
    ll ans = 0;
    for (int i = 1; i <= n-1; i++) {
        ans += b[i]*i - b[i]*(n-1-i);
    }
    cout << ans << endl;
    return 0;
}