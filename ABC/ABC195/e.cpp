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

bool dp[200005][7];
bool dp2[200005][7];

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string x;
    cin >> x;
    dp[0][0] = true;
    rep(i,n) {
        for (int j = 0; j <= 6; j++) {
            if (dp[i][j] == false) continue;
            dp[i+1][(j*10)%7] = true;
            dp[i+1][(j*10+(s[i]-'0'))%7] = true;
        }
    }
    char las = x[n-1];
    int num = -1;
    for (int i = n-1; i >= 0; i--) {
        if (x[i] != las) {
            num = i;
            break;
        }
    }
    if (num == -1) {
        if (las == 'T') {
            cout << 'T' << endl;
            return 0;
        }
        else {
            for (int i = 1; i <= 6; i++) {
                if (dp[n][i]) {
                    cout << 'A' << endl;
                    return 0;
                }
            }
        }
        cout << 'T' << endl;
        return 0;
    }
    if (las == 'T') {
        for (int i = num+1; i <= n-1; i++) {
            for (int j = 0; j <= 6; j++) {
                
            }
        }
    } else {

    }
    return 0;
}