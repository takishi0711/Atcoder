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
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    vector<P> ab(n);
    rep(i,n) cin >> ab[i].first;
    rep(i,n) {
        cin >> ab[i].second;
        ab[i].second *= -1;
    }
    sort(ab.begin(), ab.end());
    vector<int> vec;
    rep(i,n) vec.push_back(ab[i].second*(-1));
    auto Z = compress1(vec, n);
    fenwick_tree<int> fen(n+5);
    ll ans = 0;
    rep(i,n) {
        fen.add(vec[i],1);
        ans += fen.sum(vec[i], n+1);
    }
    map<P,int> mp;
    rep(i,n) mp[ab[i]]++;
    for (auto p : mp) {
        if (p.second > 1) {
            ll x = p.second;
            ans -= x*(x+1)/2;
            ans += x*x;
        }
    }
    cout << ans << endl;
    return 0;
}