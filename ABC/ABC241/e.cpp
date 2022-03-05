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
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<ll> id(1000005,-1);
    ll len = 0;
    ll x = 0;
    vector<ll> sum(1000005);
    while (id[x] < 0) {
        id[x] = len;
        len++;
        sum[len] = sum[len-1] + a[x];
        x = sum[len]%n;
    } 
    ll c = len - id[x];
    if (k <= len) cout << sum[k] << endl;
    else {
        ll ans = sum[len];
        k -= len;
        ans += (k/c) * (sum[len]-sum[id[x]]);
        k %= c;
        ans += sum[id[x]+k]-sum[id[x]];
        cout << ans << endl;
    }
    return 0;
}