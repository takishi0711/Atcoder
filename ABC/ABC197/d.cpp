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

const double pi = 3.141592653589793;

int main() {
    int n;
    cin >> n;
    double x0, y0, xn2, yn2;
    cin >> x0 >> y0 >> xn2 >> yn2;
    double xc = (x0+xn2)/2, yc = (y0+yn2)/2;
    x0 -= xc;
    y0 -= yc;
    double kaiten = pi*2/n;
    double x1 = x0*cos(kaiten) - y0*sin(kaiten);
    double y1 = x0*sin(kaiten) + y0*cos(kaiten);
    x1 += xc;
    y1 += yc;
    printf("%.10f %.10f\n", x1, y1);
    return 0;
}