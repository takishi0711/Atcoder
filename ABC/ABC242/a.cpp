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
    int a, b, c, x;
    cin >> a >> b >> c >> x;
    if (x <= a) {
        cout << 1 << endl;
    } else if (x <= b) {
        printf("%.10f\n", (double)c/(b-a));
    } else {
        cout << 0 << endl;
    }
    return 0;
}