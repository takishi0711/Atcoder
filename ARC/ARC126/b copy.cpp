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

int op(int a, int b) { return max(a,b);}
int e() { return 0;}

int main() {
    int n, m;
    cin >> n >> m;
    vector<P> box(m);
    rep(i,m) {
        cin >> box[i].first >> box[i].second;
        box[i].second *= -1;
    }
    sort(box.begin(), box.end());
    rep(i,m) box[i].second *= -1;
    segtree<int,op,e> dp(200005);
    rep(i,m) {
        int w = box[i].second;
        dp.set(w, dp.prod(0,w)+1);
    }
    cout << dp.all_prod() << endl;
    return 0;
}