#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
#define chmax(x,y) x = max(x,y);
#define chmin(x,y) x = min(x,y);
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};
const int INF = 1001001001;
const ll LINF = 1001002003004005006ll;
const double PI = acos(-1);



int main() {
    ll h, w, n;
    cin >> h >> w >> n;
    ll sx, sy;
    cin >> sx >> sy;
    sx--; sy--;
    ll gx, gy;
    cin >> gx >> gy;
    gx--; gy--;
    map<ll, multiset<ll>> mprow;
    map<ll, multiset<ll>> mpcol;
    rep(i,n) {
        ll x, y;
        cin >> x >> y;
        x--; y--;
        mprow[x].insert(y);
        mpcol[y].insert(x);
    }
    map<P, ll> mpdist;
    mpdist[P(sx, sy)] = 0;
    queue<P> q;
    q.emplace(P(sx,sy));
    while (!q.empty()) {
        auto [i,j] = q.front();
        q.pop();
        {
            auto it1 = mpcol[j].lower_bound(i);
            if (it1 != mpcol[j].begin()) {
                it1--;
                ll ni = (*it1) + 1, nj = j;
                if (P(i,j) != P(ni,nj)) {
                    if (!mpdist.count(P(ni,nj))) {
                        mpdist[P(ni,nj)] = mpdist[P(i,j)] + 1;
                        q.emplace(ni,nj);
                    }
                }
            }
        }
        {
            auto it1 = mpcol[j].lower_bound(i);
            if (it1 != mpcol[j].end()) {
                ll ni = (*it1) - 1, nj = j;
                if (P(i,j) != P(ni,nj)) {
                    if (!mpdist.count(P(ni,nj))) {
                        mpdist[P(ni,nj)] = mpdist[P(i,j)] + 1;
                        q.emplace(ni,nj);
                    }
                }
            }
        }
        {
            auto it1 = mprow[i].lower_bound(j);
            if (it1 != mprow[i].begin()) {
                it1--;
                ll ni = i, nj = (*it1) + 1;
                if (P(i,j) != P(ni,nj)) {
                    if (!mpdist.count(P(ni,nj))) {
                        mpdist[P(ni,nj)] = mpdist[P(i,j)] + 1;
                        q.emplace(ni,nj);
                    }
                }
            }
        }
        {
            auto it1 = mprow[i].lower_bound(j);
            if (it1 != mprow[i].end()) {
                ll ni = i, nj = (*it1) - 1;
                if (P(i,j) != P(ni,nj)) {
                    if (!mpdist.count(P(ni,nj))) {
                        mpdist[P(ni,nj)] = mpdist[P(i,j)] + 1;
                        q.emplace(ni,nj);
                    }
                }
            }
        }
    }
    if (!mpdist.count(P(gx,gy))) cout << -1 << endl;
    else cout << mpdist[P(gx,gy)] << endl;
    return 0;
}