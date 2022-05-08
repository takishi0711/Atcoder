#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
#define chmax(x,y) x = max(x,y);
#define chmin(x,y) x = min(x,y);
const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, -1, 0, 1 };
const int dx[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
const int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
const int INF = 1001001001;
const ll LINF = 1001002003004005006ll;
const double PI = acos(-1);

ll f(ll ai, ll a0, ll x) {
    ll ami = ai, ama = ai;
    while (1) {
        ll nami = ami*2, nama = ama*2 + x; 
        if (a0 <= nami) {
            if (nami-a0 < a0-ama) {
                return nami;
            } else {
                return ama;
            }
        } else if (nami <= a0 && a0 <= nama) {
            return a0;
        } else {

        }
        ami = nami;
        ama = nama;
    }
}

int main() {
    int n;
    ll x;
    cin >> n >> x;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    sort(a.rbegin(), a.rend());
    for (int i = 1; i < n; i++) {
        a[i] = f(a[i], a[0], x);
    }
    sort(a.rbegin(), a.rend());
    ll now_sub = a[0]-a[n-1];
    vector<P> vec;
    ll mi = a[0], ma = a[0];
    while (ma < 1e18) {
        vec.emplace_back(mi, 0);
        vec.emplace_back(ma, 0);
        mi *= 2;
        ma *= 2;
        ma += x;
    }
    mi = a[n-1], ma = a[n-1];
    while (ma < 1e18) {
        vec.emplace_back(mi, 1);
        vec.emplace_back(ma, 1);
        mi *= 2;
        ma *= 2;
        ma += x;
    }
    ll ans = now_sub;
    vector<ll> now_node(2, -INF);
    vector<int> now_ok(2, 0);
    sort(vec.begin(), vec.end());
    vec.emplace_back(1e18+3, 0);
    ll now_all = vec[0].first;
    for (auto [val, id] : vec) {
        if (val != now_all) {
            if (now_ok[0] && now_ok[1]) {
                ans = 0;
            } else if (now_ok[0] || now_ok[1]) {
                chmin(ans, abs(now_node[0]-now_node[1]));
            }
        } 
        now_node[id] = val;
        now_ok[id] ^= 1;
    }
    cout << ans << endl;
    return 0;
}