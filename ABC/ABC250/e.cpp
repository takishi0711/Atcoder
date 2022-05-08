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
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    map<ll, ll> mp;
    rep(i,n) {
        cin >> a[i];
        mp[a[i]] = rand();
    }
    rep(i,n) {
        cin >> b[i];
        mp[b[i]] = rand();
    }

    set<int> sta, stb;
    vector<ll> ida(n+1), idb(n+1);
    rep(i,n) {
        if (!sta.count(a[i])) {
            ida[i+1] = ida[i]^mp[a[i]];
            sta.insert(a[i]);
        } else {
            ida[i+1] = ida[i];
        }
        if (!stb.count(b[i])) {
            idb[i+1] = idb[i]^mp[b[i]];
            stb.insert(b[i]);
        } else {
            idb[i+1] = idb[i];
        }
    }

    int q;
    cin >> q;
    rep(qi,q) {
        int x, y;
        cin >> x >> y;
        if (ida[x] == idb[y]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}