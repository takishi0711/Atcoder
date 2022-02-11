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
    vector<ll> v(2*n);
    rep(i,2*n) cin >> v[i];
    ll ans = 0;
    int l = (2*n-1)/2;
    int r = l+1;
    while (l >= 0) {
        ans += max(v[l], v[r]);
        l--; r++;
    }
    cout << ans << endl;
    return 0;
}