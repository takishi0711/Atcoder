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
    string s;
    cin >> s;
    bool ok2 = true;
    rep(i,3) {
        if (s[i] != s[i+1]) {
            ok2 = false;
        }
    }
    if (ok2) {
        cout << "Strong" << endl;
        return 0;
    }
    int now = s[0]-'0';
    bool ok = true;
    for (int i = 1; i <= 3; i++) {
        int next = s[i]-'0';
        {
            if (next-now == 1 || (now == 9 && next == 0)) {
                now = next;
                continue;
            } else {
                ok = false;
                break;
            }
        }
    }
    if (ok) cout << "Weak" << endl;
    else cout << "Strong" << endl;
    return 0;
}