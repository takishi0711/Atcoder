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
    int x;
    cin >> x;
    if (0 <= x && x < 40) {
        cout << 40-x << endl;
    } else if (x < 70) {
        cout << 70-x << endl;
    } else if (x < 90) {
        cout << 90-x << endl;
    } else {
        cout << "expert" << endl;
    }
    return 0;
}