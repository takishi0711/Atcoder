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

struct Input {
    int D;
    vector<vector<ll>> s;
    vector<ll> c;
};

ll compute_score(Input& input, vector<ll>& out) {
    ll score = 0;
    vector<ll> last(26);
    rep(i,out.size()) {
        last[out[i]] = i+1;
        rep(j,26) {
            score -= input.c[j]*(i+1 - last[j]);
        }
        score += input.s[i][out[i]];
    }
    return score;
}

vector<ll> solve(Input& input) {
    vector<ll> out;
    rep(i,input.D) {
        ll max_score = -INF;
        int best_j = 0;
        rep(j,26) {
            out.push_back(j);
            ll score = compute_score(input, out);
            if (max_score < score) {
                max_score = score;
                best_j = j;
            }
            out.pop_back();
        }
        out.push_back(best_j);
    }
    return out;
}

int main() {
    Input input;
    cin >> input.D;
    input.c.resize(26);
    rep(i,26) cin >> input.c[i];
    input.s.resize(input.D, vector<ll>(26));
    rep(i,input.D)rep(j,26) cin >> input.s[i][j];
    auto out = solve(input);
    for (int x : out) cout << x+1 << endl;
    return 0;
}