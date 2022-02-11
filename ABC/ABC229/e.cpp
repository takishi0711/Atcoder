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

vector<int> to[200005];

int main() {
    int n, m;
    cin >> n >> m;
    rep(i,m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    vector<int> ans(n);
    dsu d(n);
    int cnt = 0;
    for (int i = n-1; i >= 1; i--) {
        cnt++;
        for (int j : to[i]) {
            if (j < i) continue;
            if (!d.same(i,j)) cnt--;
            d.merge(i,j); 
        }
        ans[i] = cnt;
    }
    for (int i = 1; i < n; i++) cout << ans[i] << endl;
    cout << 0 << endl;
    return 0;
}