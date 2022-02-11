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
    int two = 1;
    rep(i,n) two *= 2;
    vector<int> a(two);
    rep(i,n) cin >> a[i];
    int mx1 = 0;
    int num1 = -1;
    int mx2 = 0;
    int num2 = -1;
    for (int i = 0; i < two/2; i++) {
        if (a[i] > mx1) {
            mx1 = a[i];
            num1 = i;
        }
    }
    for (int i = two/2; i < two; i++) {
        if (a[i] > mx2) {
            mx2 = a[i];
            num2 = i;
        }
    }
    if (mx1 > mx2) cout << num2 << endl;
    else cout << num1 << endl;
    return 0;
}