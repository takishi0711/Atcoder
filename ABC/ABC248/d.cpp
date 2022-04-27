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
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<vector<int>> id(n+1);
    rep(i,n) {
        id[a[i]].push_back(i);
    }
    int q;
    cin >> q;
    rep(qi,q) {
        int l, r, x;
        cin >> l >> r >> x;
        l--; r--;
        int idxl = lower_bound(id[x].begin(), id[x].end(), l) - id[x].begin();
        int idxr = lower_bound(id[x].begin(), id[x].end(), r) - id[x].begin();
        if (id[x].size() == 0) {
            cout << 0 << endl;
            continue;
        }
        if (id[x].back() < l || id[x][0] > r) {
            cout << 0 << endl;
            continue;
        } 
        int ans = idxr-idxl;
        if (id[x][idxr] == r) ans++; 
        cout << ans << endl;
    }
    return 0;
}