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

vector<int> to[25];

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m), b(m);
    rep(i,m) {
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
        to[a[i]].push_back(b[i]);
        to[b[i]].push_back(a[i]);
    }
    ll ans = 1;
    vector<bool> used(n);
    rep(i,n) {
        if (to[i].size() == 0) ans *= 3;
        else {
            dsu d(n);
            set<int> st;
            for (int v : to[i]) {
                if (v > i) continue;
                st.insert(v);
            }
            for (int v : to[i]) {
                if (v > i) continue;
                for (int u : to[v]) {
                    if (u > i) continue;
                    if (st.count(u)) d.merge(v,u);
                }
            }
            if (st.size() == 0) {
                ans *= 3;
                continue;
            }
            bool ok = false;
            bool ok2 = false;
            rep(j,n) {
                if (d.leader(j) >= 3) ok = true;
                if (d.leader(j) == 2) ok2 = true;
            } 
            if (ok) {
                cout << 0 << endl;
                return 0;
            }
            if (!ok2) ans *= 2; 
        }
    }
    cout << ans << endl;
    return 0;
}