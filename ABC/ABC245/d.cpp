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
    vector<ll> a(n+1), c(n+m+1);
    rep(i,n+1) cin >> a[i];
    rep(i,n+m+1) cin >> c[i];
    vector<ll> b(m+1);
    b[m] = c[n+m]/a[n];
    for (int i = m-1; i >= 0; i--) {
        ll sum = 0;
        for (int j = i+1; j <= m; j++) {
            if (n+i-j < 0) continue;
            sum += a[n+i-j]*b[j];
        }
        b[i] = (c[n+i] - sum)/a[n]; 
    }
    rep(i,m+1) {
        cout << b[i] << " ";
    }
    cout << endl;
    return 0;
}