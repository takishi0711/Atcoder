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

vector<int> yakusu(int n) {
    vector<int> res;
    for (int i = 1; i*i <= n; i++) {
        if (n%i == 0) {
            res.push_back(i);
            if (n/i != i) res.push_back(n/i);
        }
    }
    //sort(res.begin(), res.end());
    return res;
}
    
vector<int> a(300005);
int n;

ll f(ll g) {
    ll res = 0;
    rep(i,n) {
        if (a[i]%g == 0) continue;
        res += g - (a[i]%g);
    }
    return res;
}

int main() {
    ll k;
    cin >> n >> k;
    set<int> st;
    st.insert(1);
    rep(i,n) {
        cin >> a[i];
        auto vec = yakusu(a[i]);
        for (int x : vec) st.insert(x);
    }
    vector<int> yaku;
    for (int i : st) yaku.push_back(i);
    int mx = yaku.back();
    ll big = f(mx);
    if (big <= k) {
        ll l2 = mx, r2 = 1e18;
        while (l2+1 < r2) {
            ll c = (l2+r2)/2;
            ll num = f(c);
            if (num <= k) l2 = c;
            else r2 = c;
        } 
        cout << l2 << endl;
        return 0;
    }
    int l = 0, r = yaku.size() - 1;
    while (l+1 < r) {
        ll c = (l+r)/2;
        ll num = f(yaku[c]);
        if (num <= k) l = c;
        else r = c;
    }
    int l2 = yaku[l], r2 = yaku[l+1];
    while (l2+1 < r2) {
        ll c = (l2+r2)/2;
        ll num = f(c);
        if (num <= k) l2 = c;
        else r2 = c;
    } 
    ll ans = l2;
    cout << ans << endl;
    return 0;
}