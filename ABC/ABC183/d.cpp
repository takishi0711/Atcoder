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
    ll w;
    cin >> n >> w;
    vector<ll> cnt(200005);
    rep(i,n) {
        int s, t;
        cin >> s >> t;
        ll p;
        cin >> p;
        cnt[s] += p;
        cnt[t] -= p;
    }
    rep(i,200003) {
        cnt[i+1] += cnt[i];
    }
    rep(i,200003) {
        if (cnt[i] > w) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}