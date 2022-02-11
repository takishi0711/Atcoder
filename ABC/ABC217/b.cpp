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
    vector<string> s(3);
    cin >> s[0] >> s[1] >> s[2];
    vector<bool> a(4);
    rep(i,3) {
        if (s[i] == "ABC") a[0] = true;
        if (s[i] == "ARC") a[1] = true;
        if (s[i] == "AGC") a[2] = true;
        if (s[i] == "AHC") a[3] = true;
    }
    rep(i,4) {
        if (a[i] == false) {
            if (i == 0) cout << "ABC" << endl;
            if (i == 1) cout << "ARC" << endl;
            if (i == 2) cout << "AGC" << endl;
            if (i == 3) cout << "AHC" << endl;
        }
    }
    return 0;
}