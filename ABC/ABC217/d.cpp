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
    int l, q;
    cin >> l >> q;
    set<int> st;
    st.insert(0);
    st.insert(l);
    rep(qi,q) {
        int c, x;
        cin >> c >> x;
        x;
        if (c == 1) {
            st.insert(x);
        } else {
            auto it1 = st.lower_bound(x);
            int a = *it1;
            int b = *(--it1);
            cout << a-b << endl;
        }
    } 
    return 0;
}