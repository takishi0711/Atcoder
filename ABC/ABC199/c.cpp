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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int q;
    cin >> q;
    int f = 0;
    rep(qi,q) {
        int t, a, b;
        cin >> t >> a >> b;
        a--; b--;
        if (t == 1) {
            if (f == 0) {
                char c = s[a];
                s[a] = s[b];
                s[b] = c; 
            } else {
                if (a <= n-1 && b <= n-1) {
                    a += n; b += n;
                    char c = s[a];
                    s[a] = s[b];
                    s[b] = c;                     
                } else if (a >= n && b >= n) {
                    a -= n; b -= n;
                    char c = s[a];
                    s[a] = s[b];
                    s[b] = c;
                } else {
                    if (a <= n-1) a += n;
                    else a -= n;
                    if (b <= n-1) b += n;
                    else b -= n;
                    char c = s[a];
                    s[a] = s[b];
                    s[b] = c;
                }
            }
        } else {
            f ^= 1;
        }
    }
    if (f == 1) s = s.substr(n,n) + s.substr(0,n);
    cout << s << endl;
    return 0;
}