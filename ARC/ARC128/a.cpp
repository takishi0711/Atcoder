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
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<int> ans;
    int mx, mn;
    int updown; // up = 1, down = 0;
    for (int i = 1; i < n; i++) {
        if (i == 1) {
            if (a[i-1] > a[i]) {
                //mx = i-1;
                ans.push_back(i-1);
                updown = 0;
            } else {
                updown = 1;
            }
        } else {
            if (updown == 0) {
                if (a[i-1] < a[i]) {
                    ans.push_back(i-1);
                    updown = 1;
                }
            } else {
                if (a[i-1] > a[i]) {
                    ans.push_back(i-1);
                    updown = 0;
                }
            }
        }
    }
    if ((int)(ans.size())%2 == 1) ans.push_back(n-1);
    int sz = ans.size();
    vector<int> x(n);
    rep(i,sz) {
        x[ans[i]] = 1;
    }
    rep(i,n) {
        if (i == n-1) cout << x[i] << endl;
        else cout << x[i] << " "; 
    }
    return 0;
}