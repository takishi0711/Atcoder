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
    ll n, t;
    int m;
    cin >> n >> m >> t;
    vector<ll> a(m), b(m);
    rep(i,m) cin >> a[i] >> b[i];
    ll now = n;
    ll x = 0;
    rep(i,m) {
        now -= a[i]-x;
        if (now <= 0) {
            cout << "No" << endl;
            return 0;
        }
        x = a[i];
        now += b[i]-x;
        if (now > n) now = n;
        x = b[i];
    }
    if (now <= t-x) {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    return 0;
}