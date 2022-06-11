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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<vector<int>> b(k);
    rep(i,n) {
        b[i%k].push_back(a[i]);
    }
    rep(i,k) sort(b[i].begin(), b[i].end());
    vector<int> pos(k);
    vector<int> c;
    rep(i,n) {
        c.push_back(b[i%k][pos[i%k]]);
        pos[i%k]++;
    }
    sort(a.begin(), a.end());
    if (a == c) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}