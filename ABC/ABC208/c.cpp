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
    ll n, k;
    cin >> n >> k;
    vector<pair<ll,int>> p(n);
    rep(i,n) {
        ll a;
        cin >> a;
        p[i] = pair<ll,int>(a,i);
    }
    sort(p.begin(), p.end());
    vector<ll> ans(n);
    rep(i,n) {
        ans[i] += k/n;
    }
    k %= n;
    rep(i,k) {
        ans[i]++;
    }
    vector<ll> ans2(n);
    rep(i,n) {
        ans2[p[i].second] = ans[i];
    }
    rep(i,n) cout << ans2[i] << endl;
    return 0;
}