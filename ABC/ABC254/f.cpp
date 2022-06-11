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

const int MAX_A = 200005;
int op(int a, int b) { return gcd(a,b);}
int e() { return 1;}

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n), b(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    segtree<int,op,e> sa(MAX_A), sb(MAX_A);
    for (int i = 1; i < n; i++) {
        sa.set(i,a[i]-a[i-1]);
        sb.set(i,b[i]-b[i-1]);
    }
    rep(qi,q) {
        int h1, h2, w1, w2;
        cin >> h1 >> h2 >> w1 >> w2;
        h1--; h2--; w1--; w2--;
        int ans = a[h1] + b[w1];
        ans = gcd(ans, sa.prod(h1+1, h2+1));
        ans = gcd(ans, sb.prod(w1+1, w2+1));
        cout << ans << endl;
    }
    return 0;
}