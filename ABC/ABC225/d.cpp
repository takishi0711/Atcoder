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
    int n, q;
    cin >> n >> q;
    map<int,int> fro, ba;
    rep(qi,q) {
        int t;
        cin >> t;
        if (t == 1) {
            int x, y;
            cin >> x >> y;
            ba[x] = y;
            fro[y] = x;
        } else if (t == 2) {
            int x, y;
            cin >> x >> y;
            fro[y] = 0;
            ba[x] = 0;
        } else {
            int x;
            cin >> x;
            deque<int> deq;
            deq.push_back(x);
            int now = x;
            while (fro[now] != 0) {
                deq.push_front(fro[now]);
                now = fro[now];
            }
            now = x;
            while (ba[now] != 0) {
                deq.push_back(ba[now]);
                now = ba[now];
            }
            int m = deq.size();
            cout << m << " ";
            rep(i,m) {
                if (i == m-1) cout << deq[i] << endl;
                else cout << deq[i] << " ";
            }
        }
    }
    return 0;
}