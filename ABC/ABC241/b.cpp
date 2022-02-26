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
    int n, m;
    cin >> n >> m;
    multiset<int> mst;
    rep(i,n) {
        int a;
        cin >> a;
        mst.insert(a);
    }
    rep(i,m) {
        int b;
        cin >> b;
        if (!mst.count(b)) {
            cout << "No" << endl;
            return 0;
        }
        mst.erase(mst.find(b));
    }
    cout << "Yes" << endl;
    return 0;
}