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

int dist(int si, int sj, int gi, int gj) {
    return abs(si-gi) + abs(sj-gj);
}

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

bool petok(int i, int j) {
    if (G1[i][j] > 0) return false;
    rep(dir,4) {
        int ni = i+di[dir], nj = j+dj[dir];
        if (ni<0||ni>=30||nj<0||nj>=30) continue;
        if (G1[ni][nj] > 0) return false;
    }
    return true;
}

int main() {
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

    vector<int> goal1_row(m), goal1_col(m);
    goal1_row[0] = 0; goal1_col[0] = 15;
    goal1_row[1] = 15; goal1_col[1] = 29;
    goal1_row[2] = 29; goal1_col[2] = 15;
    goal1_row[3] = 15; goal1_col[3] = 0;
    for (int i = 4; i < m; i++) {
        goal1_row[i] = 15; goal1_col[i] = 15;
    }

    vector<int> goal2_row(m), goal2_col(m);
    goal2_row[0] = 14; goal2_col[0] = 15;
    goal2_row[1] = 15; goal2_col[1] = 16;
    goal2_row[2] = 16; goal2_col[2] = 15;
    goal2_row[3] = 15; goal2_col[3] = 14;
    for (int i = 4; i < m; i++) {
        goal2_row[i] = 15; goal2_col[i] = 15;
    }
    
    bool prepar1 = true;
    bool prepar2 = true;
    bool prepar3 = true;
    set<int> prepar1_done;
    set<int> prepar2_done;
    vector<bool> preper2_done_vec(m);

    rep(_,300) {
        string move_human;
        if (_ < 0) {
            rep(man,m) {
                move_human += '.';
            }
        } else if (prepar1) { // 準備 1
            rep(man,m) {
                move_human += f1(man, hx[man], hy[man], goal1_row[man], goal1_col[man]);
                if (hx[man] == goal1_row[man] && hy[man] == goal1_col[man]) {
                    prepar1_done.insert(man);
                }
            }
            if (prepar1_done.size() == m) prepar1 = false;
        } else if (prepar2) { // 準備 2
            rep(man,m) {
                if (preper2_done_vec[man]) {
                    move_human += '.';
                    continue;
                }
                int i = hx[man], j = hy[man];
                if (man == 0) {
                    if (i == 0 || G1[i-1][j] == -1) { // 動かす
                        if (i == goal2_row[man] && j == goal2_col[man]) {
                            prepar2_done.insert(man);
                            preper2_done_vec[man] = true;
                            move_human += '.';
                        } else {
                            move_human += 'D';
                            G2[i][j]--;
                            G2[i+1][j]++;
                            hx[man]++;
                        }
                    } else { // 柵を作る
                        if (petok(i-1, j)) {
                            move_human += 'u';
                            G1[i-1][j] = -1;
                            G2[i-1][j] = -1;
                        } else {
                            move_human += '.';
                        }
                    }
                } else if (man == 1) {
                    if (j == 29 || G1[i][j+1] == -1) { // 動かす
                        if (i == goal2_row[man] && j == goal2_col[man]) {
                            prepar2_done.insert(man);
                            preper2_done_vec[man] = true;
                            move_human += '.';
                        } else {
                            move_human += 'L';
                            G2[i][j]--;
                            G2[i][j-1]++;
                            hy[man]--;
                        }
                    } else { // 柵を作る
                        if (petok(i, j+1)) {
                            move_human += 'r';
                            G1[i][j+1] = -1;
                            G2[i][j+1] = -1;
                        } else {
                            move_human += '.';
                        }
                    }
                } else if (man == 2) {
                    if (i == 29 || G1[i+1][j] == -1) { // 動かす
                        if (i == goal2_row[man] && j == goal2_col[man]) {
                            prepar2_done.insert(man);
                            preper2_done_vec[man] = true;
                            move_human += '.';
                        } else {
                            move_human += 'U';
                            G2[i][j]--;
                            G2[i-1][j]++;
                            hx[man]--;
                        }
                    } else { // 柵を作る
                        if (petok(i+1, j)) {
                            move_human += 'd';
                            G1[i+1][j] = -1;
                            G2[i+1][j] = -1;
                        } else {
                            move_human += '.';
                        }
                    }
                } else if (man == 3) {
                    if (j == 0 || G1[i][j-1] == -1) { // 動かす
                        if (i == goal2_row[man] && j == goal2_col[man]) {
                            prepar2_done.insert(man);
                            preper2_done_vec[man] = true;
                            move_human += '.';
                        } else {
                            move_human += 'R';
                            G2[i][j]--;
                            G2[i][j+1]++;
                            hy[man]++;
                        }
                    } else { // 柵を作る
                        if (petok(i, j-1)) {
                            move_human += 'l';
                            G1[i][j-1] = -1;
                            G2[i][j-1] = -1;
                        } else {
                            move_human += '.';
                        }
                    }
                } else {
                    prepar2_done.insert(man);
                    preper2_done_vec[man] = true;
                    move_human += '.';
                }

                if (prepar2_done.size() == m) prepar2 = false;
            }
        } else if (prepar3) { // 調整
            if (petok(hx[0],hy[0]+1) && petok(hx[1]+1,hy[1]) && petok(hx[2],hy[2]-1) && petok(hx[3]-1,hy[3])) { // 部屋を決定
                // ペットが最小の部屋を見つける
                vector<int> cnt(4);
                rep(pet,n) {
                    if (px[pet] < 15 && py[pet] > 15) cnt[0]++;
                    else if (px[pet] > 15 && py[pet] > 15) cnt[1]++;
                    else if (px[pet] > 15 && py[pet] < 15) cnt[2]++;
                    else if (px[pet] < 15 && py[pet] < 15) cnt[3]++; 
                }
                vector<tuple<int,int,int>> room(4);
                room[0] = make_tuple(cnt[0], -15*14, 0);
                room[1] = make_tuple(cnt[1], -14*14, 1);
                room[2] = make_tuple(cnt[2], -15*14, 2);
                room[3] = make_tuple(cnt[3], -15*15, 3);
                sort(room.begin(), room.end());
                int a, b, id;
                tie(a, b, id) = room[0];
                rep(man, m) {
                    if (man == id) {
                        move_human += '.';
                        continue;
                    }
                    if (man == 0) {
                        move_human += 'r';
                    } else if (man == 1) {
                        move_human += 'd';
                    } else if (man == 2) {
                        move_human += 'l';
                    } else if (man == 3) {
                        move_human += 'u';
                    } else {
                        move_human += '.';
                    }
                }

                prepar3 = false;
            } else { // パス
                rep(i,m) {
                    move_human += '.';
                }
            }
        } else {
            rep(man,m) {
                move_human += '.';
            }
        }
        cout << move_human << endl;

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