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

bool dp[105][305];

int main() {
    int t;
    cin >> t;
    dp[1][1] = true;
    dp[1][2] = true;
    dp[1][3] = true;
    for (int i = 1; i < 100; i++) {
        for (int j = 1; j <= 300; j++) {
            if (dp[i][j] == false) continue;
            //dp[i+1][j] = true;
            dp[i+1][j+1] = true;
            dp[i+1][(j+1)%10] = true;
            dp[i+1][j+2] = true;
            dp[i+1][(j+2)%10] = true;
            dp[i+1][j+3] = true;
            dp[i+1][(j+3)%10] = true;
        }
    }
    rep(ti,t) {
        string s;
        cin >> s;
        reverse(s.begin(), s.end());
        vector<int> kurika;
        for (int i = 1; i < 1000; i++) {
            bool ook = false;
            kurika.push_back(0);
            int ni = i;
            //int kuri = 0;
            bool ok = true;
            rep(j,s.size()) {
                if (kurika.size() == 0) {
                    ok = false;
                    break;
                }
                vector<int> kurika2;
                swap(kurika, kurika2);
                int num = s[j]-'0';
                if (num == 0) num = 10;
                int nni = ni;
                rep(g,kurika2.size()) {
                    num -= kurika2[g];
                    if (j == int(s.size())-1) {
                        while (dp[nni][num] == false && nni > 0) {
                            nni--;
                        }
                        if (nni == 0) {
                            continue;
                        }
                        ook = true;
                    } else {
                        while (dp[nni][num] == false && nni > 0) {
                            nni--;
                        }
                        if (nni == 0) {
                            continue;
                        }
                        int num2 = s[j+1]-'0';
                        if (num2 == 0) num2 = 10;
                        for (int k = num2-1; k >= 0; k--) {
                            int num3 = k*10 + num;
                            if (dp[nni][num3]) {
                                kurika.push_back(k);
                            }
                        }
                    }
                }
            }
            if (ook == true) cout << i << endl;
            else continue;
            if (ok == false) continue;
            break;
        }
    }
    return 0;
}