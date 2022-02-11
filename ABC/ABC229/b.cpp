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
    string a, b;
    cin >> a >> b;
    int n = min(a.size(), b.size());
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    rep(i,n) {
        int xa = a[i]-'0';
        int xb = b[i]-'0';
        if (xa + xb >= 10) {
            cout << "Hard" << endl;
            return 0;
        }
    }
    cout << "Easy" << endl;
    return 0;
}