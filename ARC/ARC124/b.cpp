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
    vector<ll> a(n), b(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    set<ll> ans;
    multiset<ll> bb;
    rep(i,n) {
        bb.insert(b[i]);
    }
    rep(i,n)rep(j,n) {
        if (i == j) continue;
        if ((ll)(a[0]^b[i]) != (ll)(a[1]^b[j])) continue;
        ll x = a[0]^b[i];
        if (ans.count(x)) continue;
        multiset<ll> nowb;
        rep(k,n) {
            nowb.insert(x^a[k]);
        }
        if (nowb == bb) ans.insert(x);
    }
    cout << ans.size() << endl;
    for (ll x : ans) {
        cout << x << endl;
    }
    return 0;
}