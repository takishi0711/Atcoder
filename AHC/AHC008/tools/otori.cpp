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
        if (G1[ni][nj] == -1) continue;
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

// dir から 柵文字へ変換
char dir_to_c2(int dir) {
    if (dir == 0) return 'u';
    else if (dir == 1) return 'l';
    else if (dir == 2) return 'd';
    else return 'r';
}

// man を dir 方向へ移動
void move(string& move_human, int man, int dir) {
    move_human += dir_to_c(dir);
    hx[man] += di[dir];
    hy[man] += dj[dir];
}

// 柵を dir 方向に建てる
void build(string& move_human, int man, int dir) {
    move_human += dir_to_c2(dir);
    int ni = hx[man]+di[dir], nj = hy[man]+dj[dir];
    G1[ni][nj] = -1;
    G2[ni][nj] = -1;
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
    bool prepar1 = true;
    bool wall = true;
    bool prepar2 = true; 
    set<int> prepar1_done_set;
    set<int> prepar2_done_set;
    int dir = 2;
    int cnt_stop = 0;
    bool stop = false;
    rep(_,300) {
        // 人間
        string move_human;
        if (prepar1) {
            rep(man,m) {
                if (man == 0) {
                    move_human += f1(man, hx[man], hy[man], 0, 29);
                    if (hx[man] == 0 && hy[man] == 29) {
                        prepar1_done_set.insert(man);
                    }
                } else {
                    move_human += f1(man, hx[man], hy[man], 29, 0);
                    if (hx[man] == 29 && hy[man] == 0) {
                        prepar1_done_set.insert(man);
                    }
                }
                if (prepar1_done_set.size() == m) prepar1 = false;
            }
        } else if (wall) {
            rep(man,m) {
                if (man == 0) {
                    int i = hx[man], j = hy[man];
                    if (j == 3) {
                        move_human += '.';
                        wall = false;
                    } else if (G1[i+1][j] == -1) {
                        move(move_human, man, 1);
                    } else {
                        if (petok(i+1,j)) {
                            build(move_human, man, 2);
                        } else {
                            move_human += '.';
                        }
                    }
                } else {
                    move_human += '.';
                }
            }
        } else if (prepar2) {
            rep(man,m) {
                if (man == 0) {
                    move_human += f1(man, hx[man], hy[man], 0, 29);
                    if (hx[man] == 0 && hy[man] == 29) {
                        prepar2_done_set.insert(man);
                    }
                } else {
                    move_human += f1(man, hx[man], hy[man], 0, 6);
                    if (hx[man] == 0 && hy[man] == 6) {
                        prepar2_done_set.insert(man);
                    }
                }
                if (prepar2_done_set.size() == m) prepar2 = false;
            }
        } else {
            rep(man,m) {
                if (man == 1) {
                    int i = hx[man], j = hy[man];
                    if (petok(i,j+1)) {
                        bool dog_ok = true;
                        rep(k,n) {
                            if (pt[k] == 4) {
                                if (!(px[k] == 0 && 6 < py[k])) dog_ok = false;
                            }
                        }
                        if (dog_ok) build(move_human, man, 3);
                        else move_human += '.';
                    } else {
                        move_human += '.';
                    }
                } else {
                    move_human += '.';
                }
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