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
    ll n;
    cin >> n;
    ll ans = LINF;
    ll two = 1;
    for (int b = 0; b <= 60; b++) {
        if (two > n) break;
        ll a = n/two;
        ll c = n%two;
        ll now = a+b+c;
        ans = min(ans, now);
        two *= 2;
    }
    cout << ans << endl;
    return 0;
}