#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
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
    deque<P> deq;
    rep(qi,q) {
        int t;
        cin >> t;
        if (t == 1) {
            int x, c;
            cin >> x >> c;
            deq.emplace_back(x,c);
        } else {
            int c;
            cin >> c;
            ll ans = 0;
            while (c) {
                auto [x,d] = deq.front();
                deq.pop_front();
                if (c <= d) {
                    ans += x*c;
                    deq.emplace_front(x,d-c);
                    c = 0;
                } else {
                    ans += x*d;
                    c -= d;
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}