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
    vector<P> xy(n);
    rep(i,n) {
        int x, y;
        cin >> x >> y;
        xy[i] = P(x,y);
    }
    set<P> st;
    rep(i,n)rep(j,n) {
        if (i == j) continue;
        int subx = xy[j].first - xy[i].first;
        int suby = xy[j].second - xy[i].second;
        {
            int x = abs(subx), y = abs(suby);
            int g = __gcd(x,y);
            st.insert(P(subx/g, suby/g));
        }
    }
    cout << st.size() << endl;
    return 0;
}