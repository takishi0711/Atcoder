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



int main() {
    int n, m;
    cin >> n >> m;
    if (m < 0) {
        cout << -1 << endl;
        return 0;
    }
    if (m != 0 && m > n-2) {
        cout << -1 << endl;
        return 0;
    }
    int p = 1e9;
    cout << 1 << " " << p << endl;
    for (int i = 1; i <= m; i++) {
        cout << p - i*2 << " " << p - i*2 + 1 << endl;
    }
    int l = 1, r = (n-m-1)*2;
    for (int i = 1; i <= n-m-1; i++) {
        cout << 1 + l << " " << 1 + r << endl;
        l++; r--;
    }
    return 0;
}