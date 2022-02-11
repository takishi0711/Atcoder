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

vector<int> compress1(vector<int>& v, int n) {
    vector<int> dic;
    rep(i,n) dic.push_back(v[i]);
    sort(dic.begin(), dic.end());
    dic.erase(unique(dic.begin(), dic.end()), dic.end());
    rep(i,n) v[i] = lower_bound(dic.begin(), dic.end(), v[i]) - dic.begin();
    return dic;
}

int main() {
    int t;
    cin >> t;
    rep(ti,t) {
        int n;
        cin >> n;
        vector<int> lr(2*n);
        set<int> st;
        rep(i,n) {
            cin >> lr[i] >> lr[n+i];
        }
        auto Z = compress1(lr, 2*n);
        vector<P> p;
        rep(i,n) {
            p.emplace_back(lr[i+n], -lr[i]);
        }
        sort(p.begin(), p.end());
        fenwick_tree<int> cnt(2*n+5);
        bool ok = true;
        rep(i,n) {
            int l = p[i].second*(-1);
            int r = p[i].first;
            if (cnt.sum(l,r+1) > r-l) {
                ok = false;
                break;
            }
            cnt.add(l,1);
        }
        if (ok) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}