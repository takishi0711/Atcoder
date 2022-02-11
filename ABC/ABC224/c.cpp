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
    int n;
    cin >> n;
    vector<P> p(n);
    rep(i,n) cin >> p[i].first >> p[i].second;
    sort(p.begin(), p.end());
    ll ans = n*(n-1)*(n-2)/6;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            for (int k = j+1; k < n; k++) {
                if ((p[k].first-p[j].first)*(p[j].second-p[i].second) == (p[j].first-p[i].first)*(p[k].second-p[j].second)) {
                    ans--;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}