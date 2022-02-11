#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,pair<int,int>>;
using P2 = pair<int,int>;
#define chmax(x,y) x = max(x,y);
#define chmin(x,y) x = min(x,y);
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};
const int INF = 1001001001;
const ll LINF = 1001002003004005006ll;
const double PI = acos(-1);



int main() {
    int n;
    cin >> n;
    vector<pair<ll,int>> x(n), y(n);
    rep(i,n) {
        int a, b;
        cin >> a >> b;
        x[i] = pair<ll,int>(a,i);
        y[i] = pair<ll,int>(b,i);
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    auto xmn = x[0], xmn2 = x[1], xmx = x[n-1], xmx2 = x[n-2];
    auto ymn = y[0], ymn2 = y[1], ymx = y[n-1], ymx2 = y[n-2];
    vector<pair<ll,pair<int,int>>> ans;
    ans.push_back(P(abs(xmn.first-xmx.first),P2(xmn.second,xmx.second)));
    ans.push_back(P(abs(xmn2.first-xmx.first),P2(xmn2.second,xmx.second)));
    ans.push_back(P(abs(xmn.first-xmx2.first),P2(xmn.second,xmx2.second)));
    ans.push_back(P(abs(ymn.first-ymx.first),P2(ymn.second,ymx.second)));
    ans.push_back(P(abs(ymn2.first-ymx.first),P2(ymn2.second,ymx.second)));
    ans.push_back(P(abs(ymn.first-ymx2.first),P2(ymn.second,ymx2.second)));
    sort(ans.rbegin(), ans.rend());
    if (ans[0].second.first > ans[0].second.second) swap(ans[0].second.first, ans[0].second.second);
    if (ans[1].second.first > ans[1].second.second) swap(ans[1].second.first, ans[1].second.second);
    if (ans[0].second == ans[1].second) cout << ans[2].first << endl;
    else cout << ans[1].first << endl;
    return 0;
}