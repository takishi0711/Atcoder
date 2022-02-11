#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<double,int>;
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
    priority_queue<P> q2;
    rep(i,k) {
        b[i] = round((double)(a[i])*m/n);
        q.push(P((double)b[i]/m - (double)a[i]/n, i));
        q2.push(P((double)b[i]/m - (double)a[i]/n, i));
        sumb += b[i];
    } 
    ll sub = m-sumb;
    if (sub < 0) {
        while (sub < 0) {
            int idx = q2.top().second;
            q2.pop();
            b[idx]--;
            q.push(P((double)b[idx]/m - (double)a[idx]/n, idx));
            sub++;
        }
        rep(i,k) {
            if (i != k-1) cout << b[i] << " ";
            else cout << b[i] << endl;
        }
        return 0;
    }
    while (sub > 0) {
        int idx = q.top().second;
        q.pop();
        b[idx]++;
        q.push(P((double)b[idx]/m - (double)a[idx]/n, idx));
        sub--;
    }
    vector<P> b2(k);
    rep(i,k) {
        b2[i] = q.top();
        q.pop();
    }
    while (1) {
        int mxid = b2[k-1].second;
        int mnid = b2[0].second;
        b[mxid]--; b[mnid]++;
        double mx = abs(b2[k-1].first);
        b2[k-1].first = (double)b[mxid]/m - (double)a[mxid]/n;
        b2[0].first = (double)b[mnid]/m - (double)a[mnid]/n;
        sort(b2.begin(), b2.end());
        if (abs(b2[k-1].first) >= mx) {
            b[mxid]++; b[mnid]--;
            break;
        }
    }
    rep(i,k) {
        if (i != k-1) cout << b[i] << " ";
        else cout << b[i] << endl;
    }
    return 0;
}