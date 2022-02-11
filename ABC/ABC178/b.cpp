#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y);
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};
const int INF = 1001001001;

int main() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll ans = max(a*c, max(a*d, max(b*c, b*d)));
    cout << ans << endl;
    return 0;
}