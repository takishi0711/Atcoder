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
    int ma = -1, mi = INF;
    map<int,int> mp;
    set<int> st;
    rep(qi,q) {
        int t;
        cin >> t;
        if (t == 1) {
            int x;
            cin >> x;
            mp[x]++;
            // chmax(ma,x);
            // chmin(mi,x);
            st.insert(x);
        } else if (t == 2) {
            int x, c;
            cin >> x >> c;
            if (mp[x] <= c) {
                mp[x] = 0;
                st.erase(x);
            } else {
                mp[x] -= c;
            }
        } else {
            cout << *st.rbegin() - *st.begin() << endl;
        }
    }
    return 0;
}