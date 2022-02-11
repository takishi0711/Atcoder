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

const int MAX_A = 300005;
ll op(ll a, ll b) { return a^b;}
ll e() { return 0;}

int main() {
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    segtree<ll,op,e> b(MAX_A);
    rep(i,n) b.set(i,a[i]);
    rep(qi,q) {
        int t;
        cin >> t;
        if (t == 1) {
            int x;
            ll y;
            cin >> x >> y;
            x--;
            ll f = b.get(x);
            b.set(x,f^y);
        }
        else {
            int x, y;
            cin >> x >> y;
            x--; y--;
            ll ans = b.prod(x,y+1);
            cout << ans << endl;
        }
    }
    return 0;
}