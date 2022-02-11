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
    vector<int> a(2*n);
    rep(i,2*n) cin >> a[i];
    map<int, vector<int>> mp;
    int mi = INF;
    rep(i,n) {
        chmin(mi, a[i])
        mp[a[i]].push_back(i);
    }
    int mi2 = INF;
    int be;
    bool ok = true;
    for (int x : mp[mi]) {
        if (ok) {
            be = a[x+n];
            ok = false;
        }
        chmin(mi2, a[x+n]);
    }
    if (mi2 <= mi) {
        cout << mi << " " << mi2 << endl;
        return 0;
    }
    int pos = 0;
    vector<int> ansidx;
    int be2 = be;
    bool ok2 = true;
    for (auto p : mp) {
        if (p.first > be) break;
        if (ansidx.size() > 0) {
            if (p.first == be) {
                if (be2 <= p.first) break; 
            }            
        }
        
        auto v = p.second;
        for (int i : v) {
            if (i >= pos) {
                ansidx.push_back(i);
                if (ok2) {
                    if (a[i+n] > be) {
                        be2 = a[i+n];
                        ok2 = false;
                    }
                    if (a[i+n] < be) {
                        be2 = a[i+n];
                        ok2 = false;
                    }
                }
                pos = i;
            }
        }
        ok2 = false;
    }
    rep(i,ansidx.size()) {
        cout << a[ansidx[i]] << " ";
    }
    rep(i,ansidx.size()) {
        if (i == ansidx.size()-1) cout << a[ansidx[i]+n] << endl;
        else cout << a[ansidx[i]+n] << " ";
    }
    return 0;
}