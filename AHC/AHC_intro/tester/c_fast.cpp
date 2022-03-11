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

ll evaluate(Input& input, vector<ll>& out, int k) {
    ll score = 0;
    vector<ll> last(26);
    rep(i,out.size()) {
        last[out[i]] = i+1;
        rep(j,26) {
            score -= input.c[j]*(i+1 - last[j]);
        }
        score += input.s[i][out[i]];
    }
    for (int i = out.size(); i < min((int)out.size() + k, input.D); i++) {
        rep(j,26) {
            score -= input.c[j]*(i+1 - last[j]);
        }
    }
    return score;
}

ll cost(int a, int b) {
    int d = b-a;
    return d*(d-1)/2;
}

struct State {
    vector<ll> out;
    ll score;
    vector<vector<ll>> ds;

    static State make_new(Input& input, vector<ll> out) {
        vector<vector<ll>> ds(26);
        rep(i,26) {
            ds[i].push_back(0);
        }
        rep(i,input.D) {
            ds[out[i]].push_back(i+1);
        }
        rep(i,26) {
            ds[i].push_back(input.D+1);
        }
        ll score = compute_score(input, out);
        return State{ out, score, ds };
    }

    void change(Input& input, int d, int new_i) {
        int old_i = out[d];
        int idx = lower_bound(ds[old_i].begin(), ds[old_i].end(), d+1) - ds[old_i].begin();
        int prev = ds[old_i][idx-1];
        int next = ds[old_i][idx+1];
        ds[old_i].erase(ds[old_i].begin() + idx);
        score += (cost(prev, d+1) + cost(d+1, next) - cost(prev, next))*input.c[old_i];
        idx = lower_bound(ds[new_i].begin(), ds[new_i].end(), d+1) - ds[new_i].begin();
        prev = ds[new_i][idx-1];
        next = ds[new_i][idx];
        ds[new_i].insert(ds[new_i].begin() + idx, d+1);
        score -= (cost(prev, d+1) + cost(d+1, next) - cost(prev, next))*input.c[new_i];
        score += input.s[d][new_i] - input.s[d][old_i];
        out[d] = new_i;
    }
};

vector<ll> solve(Input& input) {
    
}   

int main() {
    utility::mytm.CodeStart();
    Input input;
    // cin >> input.D;
    scanf("%d", &input.D);
    input.c.resize(26);
    // rep(i,26) cin >> input.c[i];
    rep(i,26) scanf("%d", &input.c[i]);
    input.s.resize(input.D, vector<ll>(26));
    // rep(i,input.D)rep(j,26) cin >> input.s[i][j];
    rep(i,input.D)rep(j,26) scanf("%d", &input.s[i][j]);

    vector<ll> out(input.D);
    rep(i,input.D) {
        // cin >> out[i];
        scanf("%d", &out[i]);
        out[i]--;
    }
    State state = State::make_new(input, out);

    int m;
    cin >> m;
    rep(mi,m) {
        int d, q;
        // cin >> d >> q;
        scanf("%d %d", &d, &q);
        d--; q--;
        state.change(input, d, q);
        // cout << state.score << endl;
        printf("%d\n", state.score);
    }
    return 0;
}