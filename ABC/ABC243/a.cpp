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
    int v;
    vector<int> a(3);
    cin >> v >> a[0] >> a[1] >> a[2];
    rep(i,1000000) {
        if (v < a[i%3]) {
            if (i%3 == 0) cout << 'F' << endl;
            else if (i%3 == 1) cout << 'M' << endl;
            else cout << 'T' << endl;
            return 0;
        }
        v -= a[i%3];
    }
    return 0;
}