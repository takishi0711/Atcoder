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
    vector<int> a(n);
    rep(i,n) {
        cin >> a[i];
        a[i] %= 200;
    }

    rep(x,n) {
        vector<vector<bool>> dp(205, vector<bool>(205));
        
        rep(i,n) {
            //if (i == x) continue;
            for (int j = 0; j <= 199; j++) {
                if (i == x) {
                    dp[i+1][j] = dp[i][j] | dp[i+1][j];
                    continue;
                }
                if (j == 0) dp[i+1][(j+a[i])%200] = true;
                else {
                    if (dp[i][j]) dp[i+1][(j+a[i])%200] = true;
                } 
                dp[i+1][j] = dp[i][j] | dp[i+1][j];
            }
            if (dp[n][a[x]] || dp[n][0]) {
                cout << "Yes" << endl;
                if (dp[n][a[x]]) {
                    int start = 0;
                    rep(j,n+1) {
                        //if (j == x) continue;
                        if (dp[j][a[x]]) {
                            start = j;
                            break;
                        }
                    }
                    vector<int> ans;
                    int idx = start;
                    int num = (a[x]-a[idx-1]+200)%200;
                    ans.push_back(idx-1);
                    bool ok = false;
                    if (num == 0) ok = true;
                    while (idx > 0) {
                        if (ok) break;
                        while (dp[idx][num]) idx--;
                        ans.push_back(idx);
                        num = (num-a[idx]+200)%200;
                        if (num == 0) break;
                    }
                    reverse(ans.begin(), ans.end());
                    cout << 1 << " " << x+1 << endl;
                    cout << ans.size();
                    rep(j,ans.size()) cout << " " << ans[j]+1;
                    cout << endl;
                    return 0;
                } else {
                    int start = 0;
                    rep(j,n+1) {
                        //if (j == x) continue;
                        if (dp[j][0]) {
                            start = j;
                            break;
                        }
                    }
                    vector<int> ans;
                    int idx = start;
                    int num = (0-a[idx-1]+200)%200;
                    ans.push_back(idx-1);
                    bool ok = false;
                    if (num == 0) ok = true;
                    while (idx > 0) {
                        if (ok) break;
                        while (dp[idx][num]) idx--;
                        ans.push_back(idx);
                        num = (num-a[idx]+200)%200;
                        if (num == 0) break;
                    }
                    ans.push_back(x);
                    sort(ans.begin(), ans.end());
                    cout << 1 << " " << x+1 << endl;
                    cout << ans.size();
                    rep(j,ans.size()) cout << " " << ans[j]+1;
                    cout << endl;
                    return 0;
                }
            }
        }
    }
    cout << "No" << endl;
    return 0;
}