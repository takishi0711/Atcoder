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

// vector<vector<int>> G(30, vector<int>(30));
int G1[35][35]; // pet
int G2[35][35]; // human
int px[25], py[25], pt[25];
int hx[15], hy[15];
int n, m;

// 2 点間の距離
int dist(int si, int sj, int gi, int gj) {
    return abs(si-gi) + abs(sj-gj);
}

// s から g へ行く
char f1(int id, int si, int sj, int gi, int gj) {
    int dist_now = dist(si,sj,gi,gj);
    rep(dir,4) {
        int ni = si+di[dir], nj = sj+dj[dir];
        if (ni<0||ni>=30||nj<0||nj>=30) continue;
        int dist_next = dist(ni,nj,gi,gj);
        if (dist_next < dist_now) {
            G2[si][sj]--;
            G2[ni][nj]++;
            hx[id] = ni;
            hy[id] = nj;
            if (dir == 0) {
                return 'U';
            } else if (dir == 1) {
                return 'L';
            } else if (dir == 2) {
                return 'D';
            } else {
                return 'R';
            }            
        }
    }
    return '.';
}

// 柵を作れるか
bool petok(int i, int j) {
    if (G1[i][j] > 0) return false;
    rep(dir,4) {
        int ni = i+di[dir], nj = j+dj[dir];
        if (ni<0||ni>=30||nj<0||nj>=30) continue;
        if (G1[ni][nj] > 0) return false;
    }
    return true;
}

// dir から 移動文字へ変換
char dir_to_c(int dir) {
    if (dir == 0) return 'U';
    else if (dir == 1) return 'L';
    else if (dir == 2) return 'D';
    else return 'R';
}

// man を dir 方向へ移動
void move(string& move_human, int man, int dir) {
    move_human += dir_to_c(dir);
    hx[man] += di[dir];
    hy[man] += dj[dir];
}

int main() {
    // 初期入力
    cin >> n;
    rep(i,n) {
        cin >> px[i] >> py[i] >> pt[i];
        px[i]--; py[i]--;
        G1[px[i]][py[i]]++;
    }
    cin >> m;
    rep(i,m) {
        cin >> hx[i] >> hy[i];
        hx[i]--; hy[i]--;
        G2[hx[i]][hy[i]]++;
    }

    // 目的 : みんなが一緒に動き続ける
    bool prepar = true; 
    set<int> prepar_done_set;
    int dir = 2;
    int cnt_stop = 0;
    bool stop = false;
    rep(_,300) {
        // 人間
        string move_human;
        if (prepar) {
            rep(man,m) {
                move_human += f1(man, hx[man], hy[man], 0, 0);
                if (hx[man] == 0 && hy[man] == 0) {
                    prepar_done_set.insert(man);
                }
                if (prepar_done_set.size() == m) prepar = false;
            }
        } else {
            int ni = hx[0]+di[dir], nj = hy[0]+dj[dir];
            if (ni<0||ni>=30||nj<0||nj>=30) {
                stop = true;
                cnt_stop++;
            }
            if (cnt_stop > 10) {
                stop = false;
                cnt_stop = 0;
                dir = (dir+1)%4;
            }
            if (stop) {
                rep(man,m) move_human += '.';
            } else {
                rep(man,m) move(move_human, man, dir);
            }
        }
        cout << move_human << endl;

        // ペット
        rep(pet, n) {
            string move_pet;
            cin >> move_pet;
            G1[px[pet]][py[pet]]--;
            for (char c : move_pet) {
                if (c == 'U') {
                    px[pet]--;
                } else if (c == 'L') {
                    py[pet]--;
                } else if (c == 'D') {
                    px[pet]++;
                } else if (c == 'R') {
                    py[pet]++;
                } else {
                    // '.' のとき
                }
            }
            G1[px[pet]][py[pet]]++;
        }
    }
    return 0;
}