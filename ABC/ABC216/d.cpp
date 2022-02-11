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
    int n, m;
    cin >> n >> m;
    vector<deque<int>> t(m);
    rep(i,m) {
        int k;
        cin >> k;
        rep(j,k) {
            int a;
            cin >> a;
            t[i].push_back(a);
        }
    }
    set<P> st;
    deque<int> deq;
    rep(i,m) {
        deq.push_back(i);
    }
    while (!deq.empty()) {
        int a = deq.front();
        deq.pop_front();
        if (t[a].size() == 0) continue;
        int b = t[a].front();
        t[a].pop_front();
        if (st.size() == 0) {
            st.insert(P(b,a));
            continue;
        }
        auto it = st.lower_bound(P(b,-1));
        if ((*it).first == b) {
            st.erase(*it);
            deq.push_front((*it).second);
            deq.push_front(a);
        } else {
            st.insert(P(b,a));
        }
    }
    if (st.size() == 0) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}