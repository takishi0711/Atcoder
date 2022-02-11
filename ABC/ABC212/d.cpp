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
    priority_queue<ll, vector<ll>, greater<ll>> que;
    ll sum = 0;
    rep(qi,q) {
        int t;
        cin >> t;
        if (t == 1) {
            ll p;
            cin >> p;
            que.push(p-sum);
        } else if (t == 2) {
            ll p;
            cin >> p;
            sum += p;
        } else {
            ll ans = que.top();
            que.pop();
            ans += sum;
            cout << ans << endl;
        }
    }
    return 0;
}