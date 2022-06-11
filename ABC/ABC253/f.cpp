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
// const int INF = 1001001001;
const ll LINF = 1001002003004005006ll;
const double PI = acos(-1);

using S = long long;
using F = long long;

const S INF = 8e18;

S op(S a, S b){ return std::min(a, b); }
S e(){ return 0; }
S mapping(F f, S x){ return f+x; }
F composition(F f, F g){ return f+g; }
F id(){ return 0; }

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    map<int,int> mp;
    vector<bool> quer(q+5);
    map<int, set<int>> mp2;
    vector<int> query_a(q+5);
    vector<int> t1l, t1r, t1x;
    vector<int> t2i, t2x;
    vector<int> t3i, t3j;
    rep(qi,q) {
        int t;
        cin >> t;
        query_a[qi] = t;
        if (t == 1) {
            int l, r;
            ll x;
            cin >> l >> r >> x;
            t1l.push_back(l);
            t1r.push_back(r);
            t1x.push_back(x);
        } else if (t == 2) {
            int i;
            ll x;
            cin >> i >> x;
            t2i.push_back(i);
            t2x.push_back(x);
            mp[i] = qi; 
        } else {
            int i, j;
            cin >> i >> j;
            t3i.push_back(i);
            t3j.push_back(j);
            if (mp.count(i)) {
                quer[mp[i]] = true;
                mp2[mp[i]].insert(j);
            }
        }
    }
    atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> vec(m+5);
    int pos1 = 0, pos2 = 0, pos3 = 0;
    map<P, P> mp3;
    rep(qi,q) {
        if (query_a[qi] == 1) {
            vec.apply(t1l[pos1], t1r[pos1]+1, t1x[pos1]);
            pos1++;
        } else if (query_a[qi] == 2) {
            if (quer[qi]) {
                for (auto v : mp2[qi]) {
                    mp3[P(t2i[pos2], v)] = P(vec.get(v), t2x[pos2]);
                }  
            } 
            pos2++;
        } else {
            ll ans = 0;
            if (mp3.count(P(t3i[pos3], t3j[pos3]))) {
                ans += vec.get(t3j[pos3]);
                ans += mp3[P(t3i[pos3], t3j[pos3])].second;
                ans -= mp3[P(t3i[pos3], t3j[pos3])].first;
            } else {
                ans += vec.get(t3j[pos3]);
            }
            cout << ans << endl;
            pos3++;
        }
    }
    return 0;
}