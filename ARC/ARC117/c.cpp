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

int op(int a, int b) {
    if (a > b) swap(a,b); 
    if (a == b) return a;
    if (a == 1 && b == 2) return 3;
    if (a == 1 && b == 3) return 2;
    if (a == 2 && b == 3) return 1;
    if (a == 0) return b;
    if (b == 0) return a;
}
int e() { return 0;}

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    segtree<int,op,e> dp(n);
    rep(i,n) {
        if (s[i] == 'B') dp.set(i,1);
        if (s[i] == 'W') dp.set(i,2);
        if (s[i] == 'R') dp.set(i,3);
    }
    int x = dp.all_prod();
    char ans;
    if (x == 1) ans = 'B'; 
    if (x == 2) ans = 'W'; 
    if (x == 3) ans = 'R';
    cout << ans << endl; 
    return 0;
}