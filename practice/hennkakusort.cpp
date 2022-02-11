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

struct Point {
    double px, py;
};

Point operator-(const Point& a1, const Point& a2) {
    return Point{ a1.px-a2.px, a1.py-a2.py};
}

double getangle(Point G) { // Gの偏角
    double kaku = atan2(G.py, G.px)*180.0/PI;
    return kaku;
}

double getangle2(double I1, double I2) { // [偏角 I1] - [原点] - [偏角 I2] のなす角度を求める
    double res = abs(I1-I2);
    if (res >= 180.0) return 360.0 - res;
    return res;
}

Point G[2005];

int main() {
    int n;
    cin >> n;
    rep(i,n) cin >> G[i].px >> G[i].py;

    double ans = 0;
    rep(i,n) {
        // 偏角ソート
        vector<double> vec;
        rep(j,n) {
            if (j == i) continue;
            Point SA = G[j] - G[i];
            double angle = getangle(SA);
            vec.push_back(angle);
        }
        sort(vec.begin(), vec.end());

        // 片方の点を固定し、もう片方を二分探索でもとめる
        double ret = 0.0;
        rep(j,vec.size()) {
            double target = vec[j] + 180.0;
            if (target >= 360.0) target -= 360.0;
            int idx = lower_bound(vec.begin(), vec.end(), target) - vec.begin();

            int CandIdx1 = idx % vec.size();
            int CandIdx2 = (idx + vec.size() - 1) % vec.size();
            double Candidate1 = getangle2(vec[j], vec[CandIdx1]);
            double Candidate2 = getangle2(vec[j], vec[CandIdx2]);
            ret = max({ ret, Candidate1, Candidate2});
        }
        ans = max(ans, ret);
    } 
    printf("%.10f\n", ans);
    return 0;
}