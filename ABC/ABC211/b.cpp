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
    vector<bool> a(4);
    rep(i,4) {
        string s;
        cin >> s;
        if (s == "H") a[0] = true;
        if (s == "2B") a[1] = true;
        if (s == "3B") a[2] = true;
        if (s == "HR") a[3] = true;
    }
    rep(i,4) {
        if (a[i] == false) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}