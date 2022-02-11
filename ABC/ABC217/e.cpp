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
    deque<int> deq;
    multiset<int> st;
    rep(qi,q) {
        int t;
        cin >> t;
        if (t == 1) {
            int x;
            cin >> x;
            deq.push_back(x);
        } 
        if (t == 2) {
            if (st.size() == 0) {
                int ans = deq.front();
                deq.pop_front();
                cout << ans << endl;
            } else {
                int ans = *st.begin();
                cout << ans << endl;
                st.erase(st.find(ans));
            }
        } 
        if (t == 3) {
            while (!deq.empty()) {
                int y = deq.front();
                deq.pop_front();
                st.insert(y);
            }
        }
    }
    return 0;
}