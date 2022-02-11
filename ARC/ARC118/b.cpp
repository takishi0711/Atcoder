#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,int>;
#define chmax(x,y) x = max(x,y);
#define chmin(x,y) x = min(x,y);
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};
const int INF = 1001001001;
const ll LINF = 1001002003004005006ll;



int main() {
    ll k, n, m;
    cin >> k >> n >> m;
    vector<ll> a(k);
    rep(i,k) cin >> a[i];
    vector<ll> b(k);
    ll sumb = 0;
    priority_queue<P, vector<P>, greater<P>> q;
    rep(i,k) {
        b[i] = a[i]*m/n;
        q.push(P(n*b[i] - m*a[i], i));
        sumb += b[i];
    }
    ll sub = m-sumb;
    while (sub > 0) {
        int idx = q.top().second;
        q.pop();
        b[idx]++;
        q.push(P(n*b[idx] - m*a[idx], idx));
        sub--;
    }
    
    rep(i,k) {
        if (i != k-1) cout << b[i] << " ";
        else cout << b[i] << endl;
    }
    return 0;
}