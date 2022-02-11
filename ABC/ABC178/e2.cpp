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
    vector<pair<ll,ll>> p;
    rep(i,n) {
        ll x, y;
        cin >> x >> y;
        p.emplace_back(x-y, x+y);
    }
    sort(p.begin(), p.end());
    ll ans1 = p[n-1].first - p[0].first;
    vector<pair<ll,ll>> p2;
    rep(i,n) {
        p2.emplace_back(p[i].second, p[i].first);
    }
    sort(p2.begin(), p2.end());
    ll ans2 = p2[n-1].first - p2[0].first;
    ll ans = max(ans1, ans2);
    cout << ans << endl;
    return 0;
}