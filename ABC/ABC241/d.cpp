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
    int q;
    cin >> q;
    multiset<ll> st;
    rep(qi,q) {
        int t;
        cin >> t;
        if (t == 1) {
            ll x;
            cin >> x;
            st.insert(x);
        } else if (t == 2) {
            ll x, k;
            cin >> x >> k;
            auto it = st.upper_bound(x);
            bool ok = true;
            rep(i,k) {
                if (it == st.begin()) {
                    ok = false;
                    break;
                }
                it--;
            }
            if (ok) cout << *it << endl;
            else cout << -1 << endl;
        } else {
            ll x, k;
            cin >> x >> k;
            auto it = st.lower_bound(x);
            bool ok = true;
            rep(i,k-1) {
                if (it == st.end()) {
                    ok = false;
                    break;
                }
                it++;
            }
            if (it == st.end()) ok = false;
            if (ok) cout << *it << endl;
            else cout << -1 << endl;
        }
    } 
    return 0;
}