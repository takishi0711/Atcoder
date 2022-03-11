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
    double T0 = 2e3;
    double T1 = 6e2;
    double TL = 1.9;
    random_device rnd;
    mt19937 mt(rnd());
    uniform_int_distribution<> rand26(0, 25); 
    uniform_int_distribution<> randD(0, input.D-1); 
    uniform_real_distribution<> randbool(0, 1); 
    vector<ll> out(input.D);
    rep(i,input.D) out[i] = rand26(mt);
    State state = State::make_new(input, out);
    ll cnt = 0;
    double T = T0;
    ll best = state.score;
    auto best_out = state.out;
    while (1) {
        cnt++;
        if (cnt%100 == 0) {
            double t = utility::mytm.elapsed() / TL;
            if (t >= 1.0) break;
            T = pow(T0, 1.0-t) * pow(T1, t);
        }
        ll old_score = state.score;
        if (randbool(mt) < 0.5) {
            int d = randD(mt);
            int q = rand26(mt);
            int old = state.out[d];
            state.change(input, d, q);
            if (old_score > state.score && !(randbool(mt) < exp((double)(state.score - old_score) / T))) {
                state.change(input, d, old);
            }
        } else {
            uniform_int_distribution<> randd1(0, input.D-2);
            int d1 = randd1(mt);
            uniform_int_distribution<> randd2(d1+1, min(d1+16, input.D-1));
            int d2 = randd2(mt);
            int old1 = state.out[d1], old2 = state.out[d2];
            state.change(input, d1, old2);
            state.change(input, d2, old1);
            if (old_score > state.score && !(randbool(mt) < exp((double)(state.score - old_score) / T))) {
                state.change(input, d1, old1);
                state.change(input, d2, old2);
            }
        }
        if (state.score > best) {
            best = state.score;
            best_out = state.out;
        }
    }
    return best_out;
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

    auto ans = solve(input);

    for (ll x : ans) cout << x+1 << endl;
    return 0;
}