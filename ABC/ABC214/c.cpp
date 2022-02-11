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
const double PI = acos(-1);



int main() {
    int n;
    cin >> n;
    vector<ll> s(n);
    priority_queue<P, vector<P>, greater<P>> q;
    rep(i,n) cin >> s[i];
    rep(i,n) {
        ll t;
        cin >> t;
        q.emplace(t,i);
    }
    vector<ll> ans(n,LINF);
    int cnt = 0;
    while (!q.empty()) {
        ll t = q.top().first;
        int id = q.top().second;
        q.pop();
        if (ans[id] != LINF) continue;
        ans[id] = min(ans[id],t);
        q.emplace(t+s[id], (id+1)%n);
    }
    rep(i,n) cout << ans[i] << endl;
    return 0;
}