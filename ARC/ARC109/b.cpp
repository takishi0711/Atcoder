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
    ll l = 1, r = 1e10;
    while (l+1 < r) {
        ll c = (l+r)/2;
        ll sum = (c+1)*c/2;
        if (sum <= n+1) l = c;
        else r = c;
    }
    ll ans = n-l+1;
    cout << ans << endl;
    return 0;
}