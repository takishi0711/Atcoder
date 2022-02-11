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
    int ans1 = 0;
    for (int i = 1; i <= k; i++) ans1 += i;
    ans1 *= n;
    int ans2 = 0;
    for (int i = 1; i <= n; i++) ans2 += i;
    ans2 *= 100*k;
    cout << ans1+ans2 << endl;
    return 0;
}