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

using mint = modint998244353;

// combination mod prime
// https://www.youtube.com/watch?v=8uowVvQ_-Mo&t=1619
struct combination {
  vector<mint> fact, ifact;
  combination(int n):fact(n+1),ifact(n+1) {
    //assert(n < mod);
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) fact[i] = fact[i-1]*i;
    ifact[n] = fact[n].inv();
    for (int i = n; i >= 1; --i) ifact[i-1] = ifact[i]*i;
  }
  mint operator()(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fact[n]*ifact[k]*ifact[n-k];
  }
  mint p(int n, int k) {
    return fact[n]*ifact[n-k];
  }
} comb(1000005);

int main() {
    ll l, r, v;
    cin >> l >> r >> v;
    if (v == 0) {
        if (r%4 == 0) {
            ll x = (r-1+3)/4 - (l-1+3)/4;
            ll y = (r-3+3)/4 - (l-1+3)/4;
            x = max(0ll,x); 
            y = max(0ll,y);
            mint ans = (mint)x*(x-1)/2;
            ans += (mint)y*(y-1)/2;
            cout << ans.val() << endl; 
        } else if (r%4 == 1) {
            
        } else if (r%4 == 2) {

        } else if (r%4 == 3) {

        }
    } else if (v == 1) {

    } else if (v >= r) {

    } else {
        cout << 0 << endl;
    }
    return 0;
}