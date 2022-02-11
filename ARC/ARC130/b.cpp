#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
#define chmax(x,y) x = max(x,y);
#define chmin(x,y) x = min(x,y);
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};
const int INF = 1001001001;
const ll LINF = 1001002003004005006ll;
const double PI = acos(-1);



int main() {
    ll h, w, C, q;
    cin >> h >> w >> C >> q;
    vector<pair<ll, pair<ll,ll>>> vec;
    rep(qi,q) {
        ll t, n, c;
        cin >> t >> n >> c;
        n--;
        c--;
        vec.emplace_back(t,P(n,c));
    }
    reverse(vec.begin(), vec.end());
    set<ll> row, col;
    vector<ll> ans(C);
    rep(i,q) {
        ll t, n, c;
        t = vec[i].first;
        n = vec[i].second.first;
        c = vec[i].second.second;
        if (t == 1) {
            if (row.count(n)) continue;
            ans[c] += w - col.size();
            row.insert(n);
        } else {
            if (col.count(n)) continue;
            ans[c] += h - row.size();
            col.insert(n);
        }
    }
    rep(i,C) {
        if (i == C-1) cout << ans[i] << endl;
        else cout << ans[i] << " ";
    } 
    return 0;
}