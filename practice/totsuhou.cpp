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
    ll px, py;
};

Point operator+(const Point& a1, const Point& a2) {
    return Point{ a1.px+a2.px, a1.py+a2.py };
}

Point operator-(const Point& a1, const Point& a2) {
    return Point{ a1.px-a2.px, a1.py-a2.py };
}

bool operator<(const Point& a1, const Point& a2) {
    if (a1.px < a2.px) return true;
    if (a1.px > a2.px) return false;
    if (a1.py < a2.py) return true;
    return false;
}

// 外積
ll crs(Point p1, Point p2) {
    return p1.px * p2.py - p1.py * p2.px;
}

//Point G[100005];
//vector<Point> G(100005);

int main() {
    int n;
    cin >> n;
    vector<Point> G(n);
    rep(i,n) cin >> G[i].px >> G[i].py;
    //sort(G, G+n);
    sort(G.begin(), G.end());

    vector<Point> G1, G2, Totsuhou;
    G1.push_back(G[0]); G2.push_back(G[0]);
    G1.push_back(G[1]); G2.push_back(G[1]);
    for (int i = 2; i < n; i++) {
        while (G1.size() >= 2 && crs(G1[G1.size()-1]-G1[G1.size()-2], G[i]-G1[G1.size()-1]) <= 0) G1.pop_back();
        while (G2.size() >= 2 && crs(G2[G2.size()-1]-G2[G2.size()-2], G[i]-G2[G2.size()-1]) >= 0) G2.pop_back();
        G1.push_back(G[i]);
        G2.push_back(G[i]);
    }
    for (int i = 0; i < G1.size(); i++) Totsuhou.push_back(G1[i]);
    for (int i = (int)G2.size()-2; i >= 1; i--) Totsuhou.push_back(G2[i]);

    vector<ll> ly(100005, INF), ry(100005, -INF);
    rep(i,Totsuhou.size()) {
        ll ax = Totsuhou[(i+0)%Totsuhou.size()].px, ay = Totsuhou[(i+0)%Totsuhou.size()].py;
        ll bx = Totsuhou[(i+1)%Totsuhou.size()].px, by = Totsuhou[(i+1)%Totsuhou.size()].py;
        if (ax > bx) {
            swap(ax, bx);
            swap(ay, by);
        }
        if (ax == bx) {
            ly[ax] = min({ ly[ax], ay, by});
            ry[ax] = max({ ry[ax], ay, by});
        } else {
            for (int i = ax; i <= bx; i++) {
                ll v1 = (ay * (bx-i) + by * (i-ax)) / (bx-ax);
                ll v2 = (ay * (bx-i) + by * (i-ax) + (bx-ax) - 1LL) / (bx-ax);
                ly[i] = min(ly[i], v2);
                ry[i] = max(ry[i], v1);
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i <= 1000; i++) {
        if (ly[i] <= ry[i]) ans += (ry[i]-ly[i]+1);
    }
    cout << ans-n << endl;
    return 0;
}