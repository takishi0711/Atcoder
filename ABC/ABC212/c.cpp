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
    int n, m;
    cin >> n >> m;
    vector<P> ab;
    rep(i,n) {
        int a;
        cin >> a;
        ab.push_back(P(a,1));
    }
    rep(i,m) {
        int b;
        cin >> b;
        ab.push_back(P(b,2));
    }
    sort(ab.begin(), ab.end());
    int ans = INF;
    rep(i,ab.size()-1) {
        if (ab[i].second == ab[i+1].second) continue;
        ans = min(ans, abs(ab[i].first-ab[i+1].first));
    }
    cout << ans << endl;
    return 0;
}