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
    ll m;
    cin >> n >> m;
    if (n <= 10) {
        ll now = 1;
        rep(i,n) now *= 10;
        if (m > now) {
            cout << 0 << endl;
            return 0;
        }
    }
    ll ten = 10;
    vector<ll> id(10005,-1);
    vector<ll> d(1,0);
    int len = 1;
    int x = (ten/m)%m;
    bool ok = false;;
    while (id[x] == -1) {
        if (ten >= m) ok = true;
        if (ok) id[x] = len;
        d.push_back(x);
        len++;
        ten *= 10;
        x = ten/m;
        x %= m;
    }
    if (n < len) {
        cout << d[len] << endl;
        return 0;
    }
    ll c = len - id[x];
    n -= len;
    n %= c;
    int ans = d[id[x]+n];
    cout << ans << endl;
    return 0;
}