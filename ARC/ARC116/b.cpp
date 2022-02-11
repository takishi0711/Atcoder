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

using mint = modint998244353;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    sort(a.rbegin(), a.rend());
    mint ans = 0;
    mint sum = 0;
    rep(i,n) {
        ans += (mint)a[i]*a[i];
        ans += (mint)a[i]*sum;
        sum *= 2;
        sum += a[i]; 
    }
    cout << ans.val() << endl;
    return 0;
}