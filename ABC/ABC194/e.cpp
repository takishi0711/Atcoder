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



int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<int> num(n+5);
    int now = 0;
    for (int i = 0; i <= m-1; i++) {
        num[a[i]]++;
    }
    set<int> st;
    for (int i = 0; i <= n; i++) {
        if (num[i] == 0) st.insert(i);
    }
    auto x = st.lower_bound(0);
    now = *x;
    int ans = now;
    for (int i = 1; i <= n-m; i++) {
        num[a[i-1]]--;
        if (num[a[i-1]] == 0 && a[i-1] < now) {
            now = a[i-1];
            st.insert(a[i-1]);
        }
        num[a[i+m-1]]++;
        if (a[i+m-1] == now) {
            auto it = st.upper_bound(now);
            now = *it;
            st.erase(a[i+m-1]);
        }
        ans = min(ans, now);
    }
    cout << ans << endl;
    return 0;
}