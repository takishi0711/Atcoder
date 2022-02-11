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
    ll ans = 0;
    vector<ll> ten(16);
    ten[0] = 1;
    rep(i,15) ten[i+1] = ten[i]*10;
    if (n-ten[3]+1 >= 0) ans += n-ten[3]+1;
    if (n-ten[6]+1 >= 0) ans += n-ten[6]+1;
    if (n-ten[9]+1 >= 0) ans += n-ten[9]+1;
    if (n-ten[12]+1 >= 0) ans += n-ten[12]+1;
    if (n-ten[15]+1 >= 0) ans += n-ten[15]+1;
    cout << ans << endl;
    return 0;
}