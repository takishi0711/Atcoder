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

const int MAX_A = 200005;
int op(int a, int b) { return max(a,b);}
int e() { return 0;}

int main() {
    int n, m;
    cin >> n >> m;
    vector<P> ab(m);
    rep(i,m) cin >> ab[i].first >> ab[i].second;
    sort(ab.begin(), ab.end());
    vector<int> vec;
    int now = -1;
    rep(i,m) {
        if (ab[i].first != now) {
            vec.push_back(ab[i].second);
            now = ab[i].first;
        }
    }
    segtree<int,op,e> dp(MAX_A);
    int ans = 0;
    rep(i,vec.size()) {
        int mx = dp.prod(0, vec[i])+1;
        ans = max(ans, mx);
        dp.set(vec[i], mx);
    }
    cout << ans << endl;
    return 0;
}