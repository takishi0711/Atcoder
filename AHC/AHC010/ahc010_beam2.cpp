#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y);
#define chmin(x,y) x = min(x,y);
const int di[] = { 0, -1, 0, 1 };
const int dj[] = { -1, 0, 1, 0 };
const int dx[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
const int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
const int INF = 1001001001;
const ll LINF = 1001002003004005006ll;
const double PI = acos(-1);

int tiles[31][31];
int to[8][4] = {
    {1, 0, -1, -1},
    {3, -1, -1, 0},
    {-1, -1, 3, 2},
    {-1, 2, 1, -1},
    {1, 0, 3, 2},
    {3, 2, 1, 0},
    {2, -1, 0, -1},
    {-1, 3, -1, 1},
};
int order[8] = {1, 2, 3, 0, 5, 4, 7, 6};
vector<vector<int>> can = {
    {0, 1, 4, 5, 6},
    {0, 3, 4, 5, 7},
    {2, 3, 4, 5, 6},
    {1, 2, 4, 5, 7}
};
int group[8] = {0, 0, 0, 0, 1, 1, 2, 2};

int compute_length(int si, int sj, int sd, vector<vector<bool>>& used) {
    int i = si, j = sj, d = sd;
    int length = 0;
    while (1) {
        int d2 = to[tiles[i][j]][d];
        if (d2 == -1) return 0;
        i += di[d2];
        j += dj[d2];
        if (i < 0 || i >= 30 || j < 0 || j >= 30) return 0;
        d = (d2 + 2) % 4;
        used[i*30+j][d] = true;
        length += 1;
        if (i == si && j == sj && d == sd) return length;
    }
}

int compute_score() {
    int ma1 = 0, ma2 = 0;
    vector<vector<bool>> used(905, vector<bool>(4, false));
    rep(i,30)rep(j,30)rep(d,4) {
        if (to[tiles[i][j]][d] != -1 && used[i*30+j][d] == false) {
            used[i*30+j][d] = true;
            int now = compute_length(i,j,d,used);
            if (now > ma1) {
                ma2 = ma1;
                ma1 = now;
            } else if (now > ma2) {
                ma2 = now;
            }
        } 
    }
    return ma1*ma2;
}

pair<P,int> move(int si, int sj, int sd, vector<vector<int>>& t) {
    int i = si, j = sj, d = sd;
    int d2 = to[t[i][j]][d]; // 次のタイルの方向
    if (d2 == -1) return make_pair(P(0,0), -1); // 線路が途切れている
    i += di[d2];
    j += dj[d2];
    if (i < 0 || i >= 30 || j < 0 || j >= 30) return make_pair(P(0,0), -1); // 線路が途切れている
    d = (d2 + 2) % 4; // 今居たタイルの方向
    return make_pair(P(i,j), d);
}

struct state {
    int i, j, d, gi, gj, gd, cnt;
    vector<vector<int>> til;
    state() : i(0), j(0), d(0), gi(0), gj(0), gd(0), cnt(0), til(vector<vector<int>> (0)) {};
    state(int i_, int j_, int d_, int gi_, int gj_, int gd_, int cnt_, const vector<vector<int>>& t_) : i(i_), j(j_), d(d_), gi(gi_), gj(gj_), gd(gd_), cnt(cnt_), til(t_) {};
    bool operator<(const state& s) const {
        return P(abs(i-gi) + abs(j-gj), cnt) < P(abs(s.i-s.gi) + abs(s.j-s.gj), cnt);
    }
};

state beam_search(int si, int sj, int sd, int gi, int gj, int gd, vector<vector<int>> t) {
    const int BEAM_SIZE = 200;
    vector<state> cands(1, state(si,sj,sd,gi,gj,gd,0,t));
    rep(_,400) {
        vector<state> ncands;
        for (state s : cands) {
            if (s.i == s.gi && s.j == s.gj) {
                ncands.push_back(s);
                continue;
            }
            auto p = move(s.i, s.j, s.d, s.til);
            int ni = p.first.first, nj = p.first.second, nd = p.second;
            if (nd == -1) continue;
            for (int x : can[nd]) {
                if (group[x] != group[s.til[ni][nj]]) continue;
                if (s.til[ni][nj] != tiles[ni][nj]) continue;
                ncands.push_back(state(ni,nj,nd,gi,gj,gd,s.cnt+1,s.til));
                ncands.back().til[ni][nj] = x;
            }   
        }
        sort(ncands.begin(), ncands.end());
        if (int(ncands.size()) > BEAM_SIZE) {
            ncands.resize(BEAM_SIZE);
        }
        cands = ncands;
    }
    cout << cands.size() << endl;
    // cout << cands[0].i << " " << cands[0].j << " " << cands[0].d << endl;
    return cands[0];
}

vector<vector<int>> solve() {
    vector<vector<int>> ans(30, vector<int>(30));
    rep(i,30)rep(j,30) ans[i][j] = tiles[i][j];
    vector<int> c1x(4), c1y(4), c2x(4), c2y(4);
    c1x[0] = 2; c1y[0] = 2;
    c1x[1] = 2; c1y[1] = 12;
    c1x[2] = 27; c1y[2] = 12;
    c1x[3] = 27; c1y[3] = 2;
    c2x[0] = 2; c2y[0] = 17;
    c2x[1] = 2; c2y[1] = 27;
    c2x[2] = 27; c2y[2] = 27;
    c2x[3] = 27; c2y[3] = 17;
    int si1 = 2, sj1 = 2, sd1 = 0;
    rep(i,4) {
        if (to[ans[2][2]][i] != -1) {
            sd1 = i;
            break;
        }
    } 
    int nowi = si1, nowj = sj1, nowd = sd1;
    rep(i,4) {
        auto sta = beam_search(nowi,nowj,nowd,c1x[(i+1)%4],c1y[(i+1)%4],0,ans);
        ans = sta.til;
        nowi = sta.i;
        nowj = sta.j;
        nowd = sta.d;
        cout << nowi << " " << nowj << " " << nowd << endl;
    }
    int si2 = 2, sj2 = 17, sd2 = 0;
    rep(i,4) {
        if (to[ans[2][17]][i] != -1) {
            sd2 = i;
            break;
        }
    } 
    nowi = si2, nowj = sj2, nowd = sd2;
    rep(i,4) {
        auto sta = beam_search(nowi,nowj,nowd,c2x[(i+1)%4],c2y[(i+1)%4],0,ans);
        ans = sta.til;
        nowi = sta.i;
        nowj = sta.j;
        nowd = sta.d;
    }
    return ans;
}

int main() {
    vector<string> ts(30);
    rep(i,30) cin >> ts[i];
    rep(i,30)rep(j,30) tiles[i][j] = ts[i][j]-'0';

    vector<vector<int>> ans = solve();
    rep(i,30)rep(j,30) {
        rep(k,4) {
            if (ans[i][j] == tiles[i][j]) {
                cout << k;
                break;
            }
            tiles[i][j] = order[tiles[i][j]];
        } 
    }
    cout << endl;
    return 0;
}