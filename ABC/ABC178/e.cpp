#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y);
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};
const int INF = 1001001001;

int main() {
    int n;
    cin >> n;
    ll mn = INF, mx = 0;
    pair<ll,ll> pmn, pmx;
    vector<pair<ll,ll>> p;
    rep(i,n) {
        ll x, y;
        cin >> x >> y;
        p.emplace_back(x,y);
        if (x+y < mn) {
            mn = x+y;
            pmn = {x,y};
        }
        if (x+y > mx) {
            mx = x+y;
            pmx = {x,y};
        }
    }
    ll ans1 = abs(pmx.first-pmn.first) + abs(pmx.second-pmn.second);
    sort(p.begin(), p.end());
    pmn = p[0]; pmx = p[n-1];
    ll ans2 = abs(pmx.first-pmn.first) + abs(pmx.second-pmn.second);
    vector<pair<ll,ll>> p2;
    rep(i,n) {
        p2.emplace_back(p[i].second, p[i].first);
    }
    sort(p2.begin(), p2.end());
    pmn = p2[0]; pmx = p2[n-1];
    ll ans3 = abs(pmx.first-pmn.first) + abs(pmx.second-pmn.second);
    ll ans = max(ans1, max(ans2, ans3));
    cout << ans << endl;
    return 0;
}