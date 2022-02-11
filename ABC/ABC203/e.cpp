#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
#define chmax(x,y) x = max(x,y);
#define chmin(x,y) x = min(x,y);
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};
const int INF = 1001001001;
const ll LINF = 1001002003004005006ll;
const double PI = acos(-1);



int main() {
    ll n, m;
    cin >> n >> m;
    vector<P> xy(m);
    rep(i,m) cin >> xy[i].first >> xy[i].second;
    sort(xy.begin(), xy.end());
    map<ll,int> mp;
    mp[n] = 1;
    ll ans = 1;
    ll nowx = 0;
    if (m > 0) nowx = xy[0].first;
    vector<ll> er, pu;
    rep(i,m) {
        ll x = xy[i].first;
        
        if (x > nowx) {
            for (ll u : er) {
                ans--;
                mp[u] = 0;
            }
            for (ll u : pu) {
                ans++;
                mp[u] = 1;
            }
            er.clear();
            pu.clear();
            nowx = x;
        }
        
        int ok1 = 0, ok2 = 0;
        ll y = xy[i].second;
        if (y > 0) ok1 = mp[y-1];
        if (y < n*2) ok2 = mp[y+1];
        if (ok1 == 1 || ok2 == 1) {
            if (mp[y] == 0) {
                pu.push_back(y);
            }
        } else {
            if (mp[y] == 1) {
                er.push_back(y);
            } 
        }
    }
    
    for (ll u : er) {
        ans--;
        mp[u] = 0;
    }
    for (ll u : pu) {
        ans++;
        mp[u] = 1;
    }
    
    cout << ans << endl;
    return 0;
}