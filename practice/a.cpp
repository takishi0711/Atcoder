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
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n), c(m), d(m);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    rep(i,m) cin >> c[i];
    rep(i,m) cin >> d[i];
    vector<tuple<int,int,int>> vec;
    rep(i,n) {
        vec.push_back(make_tuple(a[i], b[i], 0));
    }
    rep(i,m) {
        vec.push_back(make_tuple(c[i], d[i], 1));
    }
    sort(vec.rbegin(), vec.rend());
    multiset<int> st;
    rep(i,n+m) {
        int x, y, id;
        tie(x, y, id) = vec[i];
        if (id == 0) {
            auto it = st.lower_bound(y);
            if (it == st.end()) {
                cout << "No" << endl;
                return 0;
            }
            st.erase(it);
        } else {
            st.insert(y);
        }
    } 
    cout << "Yes" << endl;
    return 0;
}