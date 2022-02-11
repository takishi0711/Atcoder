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
    int p;
    cin >> p;
    vector<int> num(11,1);
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= i; j++) {
            num[i] *= j;
        }
    }
    int ans = 0;
    for (int i = 10; i >= 1; i++) {
        ans += p/num[i];
        p = p%num[i];
    }
    cout << ans << endl;
    return 0;
}