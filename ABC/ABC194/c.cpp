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
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    ll ans = 0;
    rep(i,n) {
        ans += (n-1)*a[i]*a[i]; 
    }
    vector<ll> s(n+1);
    rep(i,n) {
        s[i+1] = s[i] + a[i];
    }
    rep(i,n) {
        ll now = a[i] * (s[n]-s[i+1]);
        ans += now * (-2);
    }
    cout << ans << endl;
    return 0;
}