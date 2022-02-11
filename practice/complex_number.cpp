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

//ABC197 D

using C = complex<double>;

C inC() {
    double x, y;
    cin >> x >> y;
    return C(x,y);
}

int main() {
    int n;
    cin >> n;
    C s = inC();
    C t = inC();
    C o = (s+t)/2.0;
    double PI = acos(-1);
    double rad = 2*PI/n;
    C r(cos(rad), sin(rad));
    C ans = o + (s-o)*r;
    printf("%.10f %.10f\n", ans.real(), ans.imag());
    return 0;
}