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
    int n;
    cin >> n;
    vector<ll> v(2*n);
    rep(i,2*n) cin >> v[i];
    ll ans = 0;
    int l = (2*n-1)/2;
    int r = l+1;
    multiset<ll> st;
    while (l >= 0) {
        ans += max(v[l], v[r]);
        st.insert(max(v[l], v[r]));
        if (int(st.size()) > 0) {
            ll mn = *begin(st);
            if (min(v[l], v[r]) > mn) {
                ans -= mn;
                st.erase(st.find(mn));
                ans += min(v[l], v[r]);
                st.insert(min(v[l], v[r]));
            }
        }
        l--; r++;
    }
    cout << ans << endl;
    return 0;
}