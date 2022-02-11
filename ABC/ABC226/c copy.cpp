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
    set<int> st;
    vector<ll> t(n);
    vector<vector<int>> a(n);
    rep(i,n) {
        cin >> t[i];
        int k;
        cin >> k;
        rep(j,k) {
            int x;
            cin >> x;
            x--;
            a[i].push_back(x);
        }
    }
    ll ans = 0;
    st.insert(n-1);
    for (int i = n-1; i >= 0; i--) {
        if (st.count(i)) {
            ans += t[i];
            for (int j : a[i]) st.insert(j);
        }
    }
    cout << ans << endl;
    return 0;
}