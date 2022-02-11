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

using mint = modint998244353;

int main() {
    ll n;
    cin >> n;
    string ns = to_string(n);
    int m = ns.size();
    mint ans = 0;
    rep(i,m) {
        mint ten = 1;
        rep(j,i) ten *= 10;
        ans += ten*9*(1+ten*9)/2;
    }
    ll ten = 1;
    rep(i,m-1) ten *= 10;
    n = n-ten+1;
    ans += (mint)(n+1)*n/2;
    cout << ans.val() << endl;
    return 0;
}