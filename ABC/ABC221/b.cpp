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
    string s, t;
    cin >> s >> t;
    if (s == t) {
        cout << "Yes" << endl;
        return 0;
    }
    int n = s.size();
    rep(i,n-1) {
        if (s[i] != t[i]) {
            char c = s[i];
            s[i] = s[i+1];
            s[i+1] = c;
            if (s == t) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
            return 0;
        }
    }
    return 0;
}