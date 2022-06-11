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
    int n, m;
    cin >> n >> m;
    vector<ll> s(n-1);
    rep(i,n-1) cin >> s[i];
    vector<ll> x(m);
    rep(i,m) cin >> x[i];
    vector<ll> a(n);
    rep(i,n-1) {
        a[i+1] = s[i] - a[i];
    }
    map<ll,ll> mp;
    rep(i,n) {
        rep(j,m) {
            mp[a[i]-x[j]]++;
        }
    }
    ll ans = 0;
    for (auto [i,j] : mp) {
        chmax(ans, j);
    }
    cout << ans << endl;
    return 0;
}