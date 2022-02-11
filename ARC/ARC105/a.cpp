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



int main() {
    vector<int> a(4);
    rep(i,4) cin >> a[i];
    rep(si,1<<4) {
        int sum1 = 0;
        int sum2 = 0;
        rep(i,4) {
            if (si>>i&1) sum1 += a[i];
            else sum2 += a[i];
        }
        if (sum1 == sum2) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}