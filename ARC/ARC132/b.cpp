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
    vector<int> p(n);
    rep(i,n) cin >> p[i];
    int ans = INF;
    rep(_,2) {
        bool ok = true;
        int pos;
        rep(i,n-1) {
            if (p[i+1]%n == 0) {
                if (p[i]%n != n-1) ok = false; 
            } else if ((p[i+1]%n) != ((p[i]%n)+1)) {
                ok = false;
            }
            if (p[i]%n == 1) pos = i;
            if (p[i+1]%n == 1) pos = i+1;
        }
        if (ok == false) {
            reverse(p.begin(), p.end());
            continue;
        }
        if (_ == 0) {
            int ans1 = pos;
            int ans2 = n-pos+2;
            ans = min(ans, ans1);
            ans = min(ans, ans2);
        } else {
            int ans1 = pos+1;
            int ans2 = n-pos+2-1;
            ans = min(ans, ans1);
            ans = min(ans, ans2);
        }
    }
    cout << ans << endl;
    return 0;
}