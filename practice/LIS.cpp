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

// lis (strict = true のとき狭義、false のとき広義)
template<typename T>
int lis(const vector<T> &a, bool strict) {
    vector<T> lis;
    for (auto &p : a) {
        typename vector<T>::iterator it;
        if (strict) it = lower_bound(lis.begin(), lis.end(), p);
        else it = upper_bound(lis.begin(), lis.end(), p);
        if (it == lis.end()) lis.emplace_back(p);
        else *it = p;
    }
    return lis.size();
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    cout << lis(a, true) << endl;
    return 0;
}