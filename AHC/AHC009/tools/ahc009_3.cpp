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

int si, sj, ti, tj;
double p;
string h[20], v[20];
int dist_s[20][20];
int dist_t[20][20];
map<pair<P,P>,bool> mp;
double dp[205][25][25];

P seni(int i, int j, char c) {
    if (c == 'U') {
        return P(i-1,j);
    } else if (c == 'D') {
        return P(i+1,j);
    } else if (c == 'R') {
        return P(i,j+1);
    } else {
        return P(i,j-1);
    }
}

double compute_E(string s) {
    int n = s.size();
    double res = 0;
    rep(i,n+1)rep(j,21)rep(k,21) dp[i][j][k] = 0;
    dp[0][si][sj] = 1;
    set<P> st;
    st.insert(P(si,sj));
    rep(i,n) {
        auto nxst = st;
        for (auto grp : st) {
            auto[x,y] = grp;
            if  (x == ti && y == tj) {
                dp[i+1][x][y] += dp[i][x][y];
                continue;
            }
            dp[i+1][x][y] += dp[i][x][y]*p;
            auto [nx,ny] = seni(x, y, s[i]);
            if (nx<0||nx>=20||ny<0||ny>=20) continue;
            if (mp[make_pair(P(x,y), P(nx,ny))]) continue;
            dp[i+1][nx][ny] += dp[i][x][y]*(1.0-p);
            nxst.insert(P(nx,ny));
        }   
        res += dp[i+1][ti][tj]*(401-(i+1));
        st = nxst;
    }
    return res;
}

string solve() {
    double TL = 1.9;
    random_device rnd;
    mt19937 mt(rnd());
    string ans;
    string dir = "ULDR";
    P pa = P(si,sj);
    while (pa != P(ti,tj)) {
        auto [i,j] = pa;
        int dir_d;
        rep(d,4) {
            int ni = i+di[d], nj = j+dj[d];
            if (ni<0||ni>=20||nj<0||nj>=20) continue;
            if (mp[make_pair(P(i,j), P(ni,nj))]) continue;
            if (dist_t[ni][nj] < dist_t[i][j]) {
                dir_d = d;
            }
        }
        ans += dir[dir_d];
        pa.first += di[dir_d];
        pa.second += dj[dir_d];
    }
    int nsz = ans.size();

    uniform_int_distribution<> rand_dir(0, 9);
    vector<int> alpha = {1, 1, 4, 4};
    vector<int> sum_alpha(4);
    sum_alpha[0] = alpha[0];
    rep(i,3) {
        sum_alpha[i+1] = sum_alpha[i]+alpha[i+1];
    }
    while (ans.size() < 200) {
        int num = rand_dir(mt);
        int idx = upper_bound(sum_alpha.begin(), sum_alpha.end(), num) - sum_alpha.begin();
        ans += dir[idx];
    }

    double score = compute_E(ans);
    
    uniform_int_distribution<> rand_dir2(0, 3);
    uniform_int_distribution<> rand_dir3(0, 9);
    vector<int> alpha2 = {4, 4, 1, 1};
    vector<int> sum_alpha2(4);
    sum_alpha2[0] = alpha2[0];
    rep(i,3) {
        sum_alpha2[i+1] = sum_alpha2[i]+alpha2[i+1];
    }
    while (utility::mytm.elapsed() < TL) {
        uniform_int_distribution<> rands(nsz, 199);
        int idx = rands(mt);
        int co_i = -1;
        string co_ans = ans;
        int num = rand_dir(mt);
        int idx2 = upper_bound(sum_alpha2.begin(), sum_alpha2.end(), num) - sum_alpha2.begin();
        co_ans[idx] = dir[idx2];
        double now_score = compute_E(co_ans);
        if (now_score > score) {
            score = now_score;
            ans = co_ans;
        }
    }

    return ans;
}

int main() {
    utility::mytm.CodeStart();
    cin >> si >> sj >> ti >> tj >> p;
    rep(i,20) cin >> h[i];
    rep(i,19) cin >> v[i];
    rep(i,20)rep(j,19) {
        if (h[i][j] == '1') {
            mp[make_pair(P(i,j), P(i,j+1))] = true;
            mp[make_pair(P(i,j+1), P(i,j))] = true;
        }
    }
    rep(i,19)rep(j,20) {
        if (v[i][j] == '1') {
            mp[make_pair(P(i,j), P(i+1,j))] = true;
            mp[make_pair(P(i+1,j), P(i,j))] = true;
        }
    }
    {
        rep(i,20)rep(j,20) dist_s[i][j] = INF;
        dist_s[si][sj] = 0;
        queue<P> q;
        q.emplace(si,sj);
        while (!q.empty()) {
            auto [i,j] = q.front();
            q.pop();
            rep(dir,4) {
                int ni = i+di[dir], nj = j+dj[dir];
                if (ni<0||ni>=20||nj<0||nj>=20) continue;
                if (mp[make_pair(P(i,j), P(ni,nj))]) continue;
                if (dist_s[ni][nj] != INF) continue;
                dist_s[ni][nj] = dist_s[i][j] + 1;
                q.emplace(ni,nj);
            }
        }
    }

    {
        rep(i,20)rep(j,20) dist_t[i][j] = INF;
        dist_t[ti][tj] = 0;
        queue<P> q;
        q.emplace(ti,tj);
        while (!q.empty()) {
            auto [i,j] = q.front();
            q.pop();
            rep(dir,4) {
                int ni = i+di[dir], nj = j+dj[dir];
                if (ni<0||ni>=20||nj<0||nj>=20) continue;
                if (mp[make_pair(P(i,j), P(ni,nj))]) continue;
                if (dist_t[ni][nj] != INF) continue;
                dist_t[ni][nj] = dist_t[i][j] + 1;
                q.emplace(ni,nj);
            }
        }
    }

    string ans = solve();
    cout << ans << endl;
    return 0;
}