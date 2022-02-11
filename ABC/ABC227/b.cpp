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
    int n;
    cin >> n;
    vector<int> s(n);
    rep(i,n) cin >> s[i];
    set<int> x;
    for (int a = 1; a <= 400; a++) {
        for (int b = 1; b <= 400; b++) {
            x.insert(4*a*b + 3*a + 3*b);
        }
    }
    int ans = 0;
    rep(i,n) {
        if (!x.count(s[i])) ans++;
    }
    cout << ans << endl;
    return 0;
}