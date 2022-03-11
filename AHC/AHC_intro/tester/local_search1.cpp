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

vector<ll> solve(Input& input) {
    double TL = 1.9;
    random_device rnd;
    mt19937 mt(rnd());
    uniform_int_distribution<> rand26(0, 25); 
    uniform_int_distribution<> randD(0, input.D-1); 
    vector<ll> out(input.D);
    rep(i,input.D) out[i] = rand26(mt);
    ll score = compute_score(input, out);
    while (utility::mytm.elapsed() < TL) {
        int d = randD(mt);
        int q = rand26(mt);
        int old = out[d];
        out[d] = q;
        ll new_score = compute_score(input, out);
        if (score > new_score) {
            out[d] = old;
        } else {
            score = new_score;
        }
    }
    return out;
}   

int main() {
    utility::mytm.CodeStart();
    Input input;
    cin >> input.D;
    input.c.resize(26);
    rep(i,26) cin >> input.c[i];
    input.s.resize(input.D, vector<ll>(26));
    rep(i,input.D)rep(j,26) cin >> input.s[i][j];

    auto ans = solve(input);

    for (ll x : ans) cout << x+1 << endl;
    return 0;
}