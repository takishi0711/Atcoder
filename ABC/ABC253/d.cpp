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
    ll n, a, b;
    cin >> n >> a >> b;
    ll ans = (n+1)*n/2;
    ans -= a * (n/a + 1) * (n/a) / 2;
    ans -= b * (n/b + 1) * (n/b) / 2;
    ll c = a/gcd(a,b)*b;
    ans += c * (n/c + 1) * (n/c) / 2;
    cout << ans << endl;
    return 0;
}