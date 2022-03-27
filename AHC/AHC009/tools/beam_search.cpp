#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y);
#define chmin(x,y) x = min(x,y);
const int di[] = { 1, 0, -1, 0 };
const int dj[] = { 0, 1, 0, -1 };
const string ds = "DRUL";
const int dx[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
const int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
const int INF = 1001001001;
const ll LINF = 1001002003004005006ll;
const double PI = acos(-1);

struct state {
    vector<int> seq;
    vector<double> dp;
    double penalty;
    state() : seq(vector<int>()), dp(vector<double>()), penalty(0.0) {};
    state(const vector<int>& seq_, const vector<double>& dp_, double penalty_) : seq(seq_), dp(dp_), penalty(penalty_) {};
    bool operator<(const state& s) const {
        return penalty < s.penalty;
    }
};

vector<int> beam_search(int N, int L, double prob, int sp, int tp, const vector<vector<int>>& nxt) {
    // step #1. calculate distance
    vector<int> dist(N*N, -1);
    dist[tp] = 0;
    queue<int> que;
	que.push(tp);
    while (!que.empty()) {
        int u = que.front(); que.pop();
        rep(i,4) {
            if (dist[nxt[i][u]] == -1) {
                dist[nxt[i][u]] = dist[u] + 1;
                que.push(nxt[i][u]);
            }
        }
    }

    // step #2. beam search
    const int BEAM_SIZE = 200;
    vector<double> initial_dp(N * N, 0.0);
    initial_dp[sp] = 1.0;
    vector<state> cands(1, state(vector<int>(), initial_dp, dist[sp]));
    for (int i = 0; i < L; i++) {
        vector<state> ncands;
        for (state s : cands) {
            for (int j = 0; j < 4; j++) {
                vector<double> ndp(N*N, 0.0);
                for (int k = 0; k < N*N; k++) {
                    ndp[k] += s.dp[k] * prob;
                    ndp[nxt[j][k]] += s.dp[k] * (1.0-prob);
                }
                double nxt_penalty = 0.0;
                for (int k = 0; k < N*N; k++) {
                    nxt_penalty += ndp[k] * dist[k];
                }
                ndp[tp] = 0;
                ncands.push_back(state(s.seq, ndp, nxt_penalty));
                ncands.back().seq.push_back(j);
            }
        }
        sort(ncands.begin(), ncands.end());
        if (int(ncands.size()) > BEAM_SIZE) {
            ncands.resize(BEAM_SIZE);
        }
        cands = ncands;
    }
    return cands[0].seq;
}

int main() {
    // step #1. input & initial setup
    int N = 20;
    int L = 200;
    int si, sj, ti, tj;
    double prob;
    cin >> si >> sj >> ti >> tj >> prob;
    vector<string> hs(N), vs(N-1);
    rep(i,N) cin >> hs[i];
    rep(i,N-1) cin >> vs[i];
    int sp = si*N + sj;
    int tp = ti*N + tj;

    // step #2. calculate "next place"
    vector<vector<int>> realnxt(4, vector<int>(N*N));
    rep(i,N*N) {
        int x = i/N, y = i%N;
        realnxt[0][i] = (x == N-1 || vs[x][y] == '1' ? i : i+N); // (x, y) --> (x+1, y)
        realnxt[1][i] = (y == N-1 || hs[x][y] == '1' ? i : i+1); // (x, y) --> (x, y+1)
        realnxt[2][i] = (x == 0 || vs[x-1][y] == '1' ? i : i-N); // (x, y) --> (x-1, y)
        realnxt[3][i] = (y == 0 || hs[x][y-1] == '1' ? i : i-1); // (x, y) --> (x, y-1)
    }
    vector<vector<int>> nxt = realnxt;
    nxt[0][tp] = tp;
    nxt[1][tp] = tp;
    nxt[2][tp] = tp;
    nxt[3][tp] = tp;

    // step #3. beam search
    vector<int> seq = beam_search(N, L, prob, sp, tp, realnxt);

    // step #4. output the answer
    for (int i = 0; i < L; i++) {
		cout << ds[seq[i]];
	}
    cout << endl;
    return 0;
}