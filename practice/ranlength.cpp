#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y);
#define chmin(x,y) x = min(x,y);
const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, -1, 0, 1 };
const int dx[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
const int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
const int INF = 1001001001;
const ll LINF = 1001002003004005006ll;
const double PI = acos(-1);



int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    // ランレングス圧縮
    vector<pair<char, ll>> vec;
    ll cnt = 0;
    rep(i,n) {
        cnt++;
        if (i == n-1 || s[i] != s[i+1]) {
            vec.push_back(make_pair(s[i], cnt));
            cnt = 0;
        }
    } 

    ll ret = 0;
    rep(i,vec.size()) {
        ret += vec[i].second * (vec[i].second-1) / 2;
    }
    ll ans = (ll)(n-1)*n/2 - ret;
    cout << ans << endl;
    return 0;
}