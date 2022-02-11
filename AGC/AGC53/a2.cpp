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
    vector<int> a(n+1);
    rep(i,n+1) cin >> a[i];
    int k = 0;
    for (int i = 1; i < 10005; i++) {
        int now = a[0];
        bool ok = true;
        rep(j,n-1) {
            if (s[j] == '<') {
                now += i;
                if (a[j+1] < now) {
                    ok = false;
                    break;
                }
                now = a[j+1];
            } else {
                now -= i;
                if (a[j+1] > now) {
                    ok = false;
                    break;
                }
                now = a[j+1];
            }
        }
        if (ok) {
            if (s[n-1] == '<') {
                now += i;
                if (a[n] < now) ok = false;
            } else {
                now -= i;
                if (a[n] > now) ok = false;
            }
        }
        if (ok == false) {
            k = i-1;
            break;
        }
    }
    if (k == 0) {
        cout << k << endl;
        return 0;
    }
    vector<vector<int>> ans(k, vector<int>(n+1));
    rep(i,k) {
        ans[i][0] = a[0]/k;
    }
    ans[0][0] += a[0]%k;
    int now = a[0];
    rep(i,n) {
        if (a[i+1] <= k) {
            int x = a[i+1];
            rep(j,k) {
                if (x) {
                    ans[j][i+1] = 1;
                    x--;
                }
            }
        } else {
            rep(j,k) {
                ans[j][i+1] = a[i+1]/k;
            }
            ans[0][i+1] += a[i+1]%k;
        }
    }
    cout << k << endl;
    rep(i,k) {
        rep(j,n+1) cout << ans[i][j] << " ";
        cout << endl;
    }
    return 0;
}