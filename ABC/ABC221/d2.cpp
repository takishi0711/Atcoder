#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y);
#define chmin(x,y) x = min(x,y);
const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, -1, 0, 1 };
const int dx[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
const int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
const int INF = 1001001001;
const ll LINF = 1001002003004005006ll;
const double PI = acos(-1);



int main() {
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    vector<P> event;
    rep(i,n) {
        cin >> a[i] >> b[i];
        event.push_back(P(a[i], 0));
        event.push_back(P(a[i]+b[i], 1));
    }
    sort(event.begin(), event.end());
    vector<ll> ans(n+1);
    ll now = 0;
    ll sum = 0;
    rep(i,event.size()) {
        int day = event[i].first;
        int id = event[i].second;
        if (day != now) {
            ans[sum] += day-now;
        }
        now = day;
        if (id == 0) sum++;
        else sum--;
    }
    for (int i = 1; i <= n; i++) {
        if (i == n) cout << ans[i] << endl;
        else cout << ans[i] << " ";
    }
    return 0;
}