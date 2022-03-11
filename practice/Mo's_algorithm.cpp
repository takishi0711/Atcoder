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

// ABC242 G - Range Pairing Query

int D, W;
struct Q {
    int l, r, i;
    Q(int l, int r, int i) : l(l), r(r), i(i) {}
    bool operator<(const Q& a) const {
        if (r/W != a.r/W) return r/W < a.r/W;
        return l < a.l;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    int q;
    cin >> q;
    D = sqrt(q)+1;
    W = n/D+1;

    vector<Q> qs;
    rep(i,q) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        qs.emplace_back(l, r, i);
    }
    sort(qs.begin(), qs.end());

    vector<int> cnt(100005);
    int now = 0;

    auto add = [&](int i, int x=1) {
        now -= cnt[a[i]]/2;
        cnt[a[i]] += x;
        now += cnt[a[i]]/2;
    };
    auto del = [&](int i) { add(i,-1);};


    int l = 0, r = -1;
    vector<int> ans(q);
    for (auto [ql, qr, qi] : qs) {
        while (l < ql) { del(l); l++;}
        while (l > ql) { l--; add(l);}
        while (r > qr) { del(r); r--;}
        while (r < qr) { r++; add(r);}
        ans[qi] = now;
    } 

    rep(qi,q) printf("%d\n", ans[qi]);
    return 0;
}