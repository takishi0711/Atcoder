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
    int a, b;
    cin >> a >> b;
    int x = a+b, y = b;
    int ans = 0;
    if (x >= 15 && y >= 8) ans = 1;
    else if (x >= 10 && y >= 3) ans = 2;
    else if (x >= 3) ans = 3;
    else ans = 4;
    cout << ans << endl; 
    return 0;
}