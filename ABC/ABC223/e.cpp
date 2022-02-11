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
//const int INF = 1001001001;
const ll LINF = 1001002003004005006ll;
const double PI = acos(-1);

using S = long long;
using F = long long;

const S INF = 8e18;

S op(S a, S b){ return std::min(a, b); }
S e(){ return INF; }
S mapping(F f, S x){ return f+x; }
F composition(F f, F g){ return f+g; }
F id(){ return 0; }

int main() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<S> v(n+1);
    rep(i,n) {
        if (s[i] == '(') {
            v[i+1] = v[i]+1;
        } else {
            v[i+1] = v[i]-1;
        }
    }
    lazy_segtree<S, op, e, F, mapping, composition, id> seg(v);
    rep(qi,q) {
        int t;
        cin >> t;
        int l, r;
        cin >> l >> r;
        if (t == 1) {
            if (s[l] == '(') {
                seg.apply(l, -1);
                seg.apply(r, 1);
            } else {
                seg.apply(l, 1);
                seg.apply(r, -1);
            }
            if (s[r] == '(') {
                seg.apply(r, -1);
                seg.apply(l, 1);
            } else {
                seg.apply(r, 1);
                seg.apply(l, -1);
            }
          	swap(s[l-1], s[r-1]);
        } else {
            if (seg.get(l-1) != seg.get(r)) {
                cout << "No" << endl;
            } else {
                int mn = seg.prod(l-1, r+1);
                if (mn < seg.get(l-1)) {
                    cout << "No" << endl;
                } else {
                    cout << "Yes" << endl;
                }
            }
            
        }
    }
    return 0;
}