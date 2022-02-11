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



int main() {
    int n;
    cin >> n;
    vector<pair<ll,ll>> t(n);
    rep(i,n) {
        ll a, b;
        cin >> a >> b;
        t[i].first = a+b+a;
        t[i].second = a+b;
    }
    sort(t.rbegin(), t.rend());
    vector<ll> ao(n);
    ao[0] = t[0].first-t[0].second;
    rep(i,n-1) {
        ao[i+1] = ao[i] + t[i+1].first-t[i+1].second;
    }
    ll st = 0;
    rep(i,n) {
        st += t[i].second;
        if (st > ao[n-1]-ao[i]) {
            cout << i+1 << endl;
            return 0;
        }
    }
    return 0;
}