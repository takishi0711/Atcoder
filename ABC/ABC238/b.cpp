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
    int n;
    cin >> n;
    vector<int> x;
    int now = 0;
    x.push_back(now);
    rep(i,n) {
        int a;
        cin >> a;
        now = (now+a)%360;
        x.push_back(now);
    }
    x.push_back(360);
    sort(x.begin(), x.end());
    int ans = 0;
    for (int i = 1; i < x.size(); i++) {
        ans = max(ans, x[i]-x[i-1]);
    }
    cout << ans << endl;
    return 0;
}