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
using mint = modint998244353;

int main() {
    int n, m;
    cin >> n >> m;
    dsu d(n);
    rep(i,m) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        to[u].push_back(v);
        to[v].push_back(u);
        d.merge(u,v);
    } 
    set<int> lead;
    map<int, ll> mp;
    rep(i,n) {
        mp[d.leader(i)] += to[i].size();
        lead.insert(d.leader(i));
    }
    mint ans = 1;
    rep(i,n) {
        if (d.leader(i) == i) {
            if (mp[i]/2 == d.size(i)) ans *= 2;
            else {
                cout << 0 << endl;
                return 0;
            }
        }
    }
    cout << ans.val() << endl;
    return 0;
}