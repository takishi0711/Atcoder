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
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    map<ll,int> mp;
    rep(i,n) {
        cin >> a[i];
        mp[a[i]]++;
    }
    rep(qi,q) {
        ll k;
        cin >> k;
        ll l = 0, r = 1e18;
        r += 1000000;
        bool ok = true;
        while (l+1 < r) {
            ll c = (l+r)/2;
            int idx = upper_bound(a.begin(), a.end(), c) - a.begin();
            ll d = c-idx;
            if (mp[c] == 1) {
                if (d >= k) r = c;
                else l = c;
            } else {
                if (d == k) {
                    cout << c << endl;
                    ok = false;
                    break;
                }
                if (d > k) r = c;
                else l = c;
            }
        }
        if (ok) cout << r << endl;
    }
    return 0;
}