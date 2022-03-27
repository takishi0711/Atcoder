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
    rep(i,n) {
        cin >> a[i];
        if (a[i] == 0) a[i] = -1;
    }
    
    vector<int> asum(n+1);
    rep(i,n) {
        asum[i+1] = asum[i] + a[i];
    }
    int ansma = 0, ansmi = 0;
    int nowmi = 0;
    for (int i = 1; i <= n; i++) {
        ansma = max(ansma, asum[i]-nowmi);
        nowmi = min(nowmi, asum[i]); 
    }
    int nowma = 0;
    for (int i = 1; i <= n; i++) {
        ansmi = min(ansmi, asum[i]-nowma);
        nowma = max(nowma, asum[i]); 
    }
    cout << ansma-ansmi+1 << endl;
    return 0;
}