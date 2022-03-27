#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y);
#define chmin(x,y) x = min(x,y);
const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, -1, 0, 1 };
const int dx[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
const int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
const int INF = 1001001001;
const ll LINF = 1001002003004005006ll;
const double PI = acos(-1);

namespace utility {
    struct timer {
        chrono::system_clock::time_point start;

        // 開始時間を記録
        void CodeStart() {
            start = chrono::system_clock::now();
        }

        // 経過時間 (s) を返す
        double elapsed() const {
            using namespace std::chrono;
            return (double)duration_cast<milliseconds>(system_clock::now() - start).count()/1000;
        }
    } mytm;
}

int n;
vector<int> x(205), y(205), r(205);
vector<int> a(205), b(205), c(205), d(205);

double compute_score() {
    double res = 0;
    rep(i,n) {
        double s = (double)(c[i]-a[i])*(d[i]-b[i]);
        res += 1.0 - (1.0 - min((double)r[i], s)/max((double)r[i], s))*(1.0 - min((double)r[i], s)/max((double)r[i], s));
    }
    res /= n;
    res *= 1e9;
    return res;
}

void expansion_reduction(int id, int dir, bool flag) {
    int x = flag ? 1 : -1;
    if (dir == 0) {
        a[id] -= x;
    } else if (dir == 1) {
        b[id] -= x;
    } else if (dir == 2) {
        c[id] += x;
    } else {
        d[id] += x;
    }
}

bool out_bnd(int id) {
    if (a[id]<0||b[id]<0||c[id]>10000||d[id]>10000) return true;
    return false;
}

bool overlapping(int id) {
    rep(i,n) {
        if (i == id) continue;
        if ((max(a[id], a[i]) < min(c[id], c[i])) && (max(b[id], b[i]) < min(d[id], d[i]))) {
            return true;
        }
    }
    return false;
}

void solve() {
    double TL = 4.9;
    random_device rnd;
    mt19937 mt(rnd());
    uniform_int_distribution<> rand_rectangle(0, n-1);
    uniform_int_distribution<> rand_dir(0, 3);
    double score = compute_score();
    while (utility::mytm.elapsed() < TL) {
        int idx_rec = rand_rectangle(mt);
        int dir = rand_dir(mt);
        expansion_reduction(idx_rec, dir, true);
        if (out_bnd(idx_rec)) {
            expansion_reduction(idx_rec, dir, false);
            continue;
        }
        if (overlapping(idx_rec)) {
            expansion_reduction(idx_rec, dir, false);
            continue;
        }
        double now_score = compute_score();
        if (now_score <= score) {
            expansion_reduction(idx_rec, dir, false);
            continue;
        }
        score = now_score;
    }
}

int main() {
    utility::mytm.CodeStart();
    cin >> n;
    rep(i,n) cin >> x[i] >> y[i] >> r[i];
    rep(i,n) {
        a[i] = x[i];
        b[i] = y[i];
        c[i] = x[i]+1;
        d[i] = y[i]+1;
    }

    solve();

    rep(i,n) {
        printf("%d %d %d %d\n", a[i], b[i], c[i], d[i]);
    }
    return 0;
}