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

int ans[50005][16];

int main() {
    int n, l;
    cin >> n >> l;
    int cnt = 0;
    int n2 = n;
    while (n2 > 1) {
        n2 = (n2+2)/3;
        cnt++;
    }
    
    rep(i,l) {
        if (i == 0) {
            rep(j,n) ans[j][i] = 2;
            continue;
        }
        if (l-i <= cnt) {
            break;
        } else {
            rep(j,n) ans[j][i] = 0;
        }
    }
    int pos = 0;
    for (int si = 0; si < pow(3,cnt); si++) {
        //string tmp = to_string(si);
        int tmp = si;
        vector<int> bit(cnt);
        int d = 0;
        while (tmp > 0) {
            bit[d] = tmp%3;
            d++;
            tmp /= 3;
        }
        reverse(bit.begin(), bit.end());
        for (int i = 0; i < cnt; i++) {
            ans[pos][l-cnt+i] = bit[i];
        }
        pos++;
        if (pos == n) break;
    }
    rep(i,3) {
        rep(j,n) {
            rep(k,l) {
                cout << (ans[j][k]+i)%3;
            }
            cout << endl;
        } 
    }
    return 0;
}