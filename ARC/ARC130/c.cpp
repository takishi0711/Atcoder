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
    string a, b;
    cin >> a >> b;
    int na = a.size(), nb = b.size();
    bool sw = false;
    if (!(na <= nb)) {
        swap(a,b);
        swap(na,nb);
        sw = true;
    }
    vector<int> cnta(10), cntb(10);
    rep(i,na) cnta[a[i]-'0']++;
    rep(i,nb) cntb[b[i]-'0']++;
    for (int sa = 1; sa <= 9; sa++) {
        for (int )
    }
    return 0;
}