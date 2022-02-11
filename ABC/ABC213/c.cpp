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
    int h, w, n;
    cin >> h >> w >> n;
    vector<int> a(n), b(n);
    vector<int> row, col;
    rep(i,n) {
        cin >> a[i] >> b[i];
    }
    auto aa = compress1(a, n);
    auto bb = compress1(b, n);
    rep(i,n) {
        cout << a[i]+1 << " " << b[i]+1 << endl;
    }
    return 0;
}