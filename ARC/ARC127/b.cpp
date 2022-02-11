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
            vector<int> num(3,0);
            rep(j,n) {
                ans[j][i] = num[ans[j][i-1]];
                num[ans[j][i-1]] = (num[ans[j][i-1]]+1)%3;
            }
        } else {
            rep(j,n) ans[j][i] = 0;
        }
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