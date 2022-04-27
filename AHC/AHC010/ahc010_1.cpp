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

int compute_score(vector<vector<int>>& t) {
    int ma1 = 0, ma2 = 0;
    vector<vector<bool>> used(905, vector<bool>(4, false));
    rep(i,30)rep(j,30)rep(d,4) {
        if (to[t[i][j]][d] != -1 && used[i*30+j][d] == false) {
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

vector<vector<int>> solve() {
    vector<vector<int>> ans(30, vector<int>(30));
    rep(i,30)rep(j,30) ans[i][j] = tiles[i][j];
    double TL = 1.9;
    random_device rnd;
    mt19937 mt(rnd());
    uniform_int_distribution<> rand2(0, 1);
    uniform_int_distribution<> rand4(0, 3);
    int ma = compute_score(ans);
    while (utility::mytm.elapsed() < TL) {
        vector<vector<int>> now(30, vector<int>(30));
        rep(i,30)rep(j,30) {
            if (group[tiles[i][j]] == 0) {
                now[i][j] = (tiles[i][j] + rand4(mt))%4;
            } else {
                if (rand2(mt)) now[i][j] = order[tiles[i][j]];
            }
        }
        int now_score = compute_score(now);
        if (now_score > ma) {
            ans = now;
            ma = now_score;
        }
    }
    return ans;
}

int main() {
    utility::mytm.CodeStart();
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