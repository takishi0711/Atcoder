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

struct maxStack {
    stack<ll> a, mx;
    ll getMax() { return mx.size() ? mx.top() : 0;}
    void push(ll x) {
        a.push(x);
        mx.push(max(x, getMax()));
    }
    ll top() { assert(a.size()); return a.top();}
    void pop() { a.pop(); mx.pop();}
    int size() { return a.size();}
};

struct maxQueue {
    maxStack s, t;
    void mv() {
        while (t.size()) {
            s.push(t.top());
            t.pop();
        }
    }
    void push(ll x) { t.push(x);}
    void pop() {
        if (!s.size()) mv();
        s.pop();
    }
    ll getMax() {
        return max(s.getMax(), t.getMax());
    }
};

int main() {
    int h, w;
    int h1, w1, h2, w2;
    cin >> h >> w >> h1 >> w1 >> h2 >> w2;
    chmin(h2, h1);
    chmin(w2, w1);
    vector<vector<ll>> a(h+1, vector<ll>(w+1));
    rep(i,h)rep(j,w) cin >> a[i+1][j+1];
    rep(i,h)rep(j,w+1) a[i+1][j] += a[i][j];
    rep(i,h+1)rep(j,w) a[i][j+1] += a[i][j];
    vector<vector<ll>> a2(h-h2+1, vector<ll>(w-w2+1));
    auto sum = [&](int i, int j, int nh, int nw) {
        int ti = i+nh, tj = j+nw;
        ll res = a[ti][tj];
        res -= a[ti][j];
        res -= a[i][tj];
        res += a[i][j];
        return res;
    };
    rep(i,h-h2+1)rep(j,w-w2+1) {
        a2[i][j] = sum(i,j,h2,w2);
    }

    vector<vector<ll>> a3(h-h2+1, vector<ll>(w-w1+1));
    rep(i,h-h2+1) {
        maxQueue q;
        rep(j,w1-w2+1) q.push(a2[i][j]);
        rep(j,w-w1+1) {
            if (j) {
                q.push(a2[i][w1-w2+j]);
                q.pop();
            }
            a3[i][j] = q.getMax();
        }
    }

    vector<vector<ll>> a4(h-h1+1, vector<ll>(w-w1+1));
    rep(j,w-w1+1) {
        maxQueue q;
        rep(i,h1-h2+1) q.push(a3[i][j]);
        rep(i,h-h1+1) {
            if (i) {
                q.push(a3[h1-h2+i][j]);
                q.pop();
            }
            a4[i][j] = q.getMax();
        }
    }

    ll ans = 0;
    rep(i,h-h1+1)rep(j,w-w1+1) {
        ll now = sum(i,j,h1,w1);
        now -= a4[i][j];
        chmax(ans, now);
    }
    cout << ans << endl;
    return 0;
}