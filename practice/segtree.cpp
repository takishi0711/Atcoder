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

const int MAX_A = 300005;
int op(int a, int b) { return max(a,b);}
int e() { return 0;}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    segtree<int,op,e> dp(MAX_A);
    rep(i,n) {
        int x = a[i];
        int l = max(x-k,0), r = min(x+k+1,MAX_A);
        int now = dp.prod(l,r)+1;
        dp.set(x, now);
    }
    int ans = dp.prod(0,MAX_A);
    cout << ans << endl;
    return 0;
}