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
vector<P> task1;
vector<P> task2;
const int left_col = 1; // 左何列空けるか
vector<P> close_point(5);

// 2 点間の距離
int dist(int si, int sj, int gi, int gj) {
    return abs(si-gi) + abs(sj-gj);
}

int dist2(int si, int sj, int gi, int gj) {
    vector<vector<int>> res(35, vector<int>(35, INF));
    res[si][sj] = 0;
    queue<P> q;
    q.emplace(si,sj);
    while (!q.empty()) {
        int i = q.front().first;
        int j = q.front().second; q.pop();
        rep(dir,4) {
            int ni = i+di[dir], nj = j+dj[dir];
            if (ni<0||ni>=30||nj<0||nj>=30) continue;
            if (G1[ni][nj] == -1) continue;
            if (res[ni][nj] != INF) continue;
            res[ni][nj] = res[i][j]+1;
            q.emplace(ni,nj);
        }
    } 
    return res[gi][gj];
}

// s から g へ行く
char f1(int id, int si, int sj, int gi, int gj) {
    int dist_now = dist2(si,sj,gi,gj);
    for (int dir = 3; dir >= 0; dir--) {
        int ni = si+di[dir], nj = sj+dj[dir];
        if (ni<0||ni>=30||nj<0||nj>=30) continue;
        if (G1[ni][nj] == -1) continue;
        int dist_next = dist2(ni,nj,gi,gj);
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
    if (G2[i][j] > 0) return false;
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

void make_task1() {
    task1.push_back(P(1,2));   
    task1.push_back(P(0,3));
    rep(i,29-left_col-1) {
        task1.push_back(P(0,3));
        task1.push_back(P(1,1));
    }   
    task1.push_back(P(0,2));
    task1.push_back(P(1,0));
    task1.push_back(P(0,2));
    task1.push_back(P(0,2));
    rep(i,29-left_col) {
        task1.push_back(P(0,1));
        task1.push_back(P(1,3));
    }
    task1.push_back(P(0,2));
    task1.push_back(P(1,2));
    task1.push_back(P(0,0));
}

void make_task2() {
    task2.push_back(P(1,3));
    task2.push_back(P(0,2));
    task2.push_back(P(1,3));
    task2.push_back(P(0,2));
    task2.push_back(P(0,2));
    rep(i,29-left_col+1) {
        task2.push_back(P(0,3));
    }
    rep(i,29-left_col) {
        task2.push_back(P(0,1));
        task2.push_back(P(1,3));
    }
    task2.push_back(P(0,2));
    task2.push_back(P(1,2));
    task2.push_back(P(0,0));
}

// ペットの位置を分類
int where_room(int i, int j) {
    if (j < left_col+1) return 10;
    else {
        return i/3;
    }
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

    make_task1();
    make_task2();

    close_point[0] = P(3, left_col);
    close_point[1] = P(9, left_col);
    close_point[2] = P(15, left_col);
    close_point[3] = P(21, left_col);
    close_point[4] = P(27, left_col);

    vector<P> goal1(m);
    goal1[0] = P(0,left_col-1);
    goal1[1] = P(6,left_col);
    goal1[2] = P(12,left_col);
    goal1[3] = P(18,left_col);
    goal1[4] = P(24,left_col);
    for (int i = 5; i < m; i++) {
        goal1[i] = P(16,0);
    }

    bool prepar1 = true;
    bool wall = true;
    bool prepar2 = true; 
    bool close1 = true;
    bool close_dog = true;
    bool pre_nodog = true;
    set<int> open_room;
    rep(i,10) open_room.insert(i);
    set<int> prepar1_done_set;
    set<int> prepar2_done_set;
    set<int> wall_done_set;
    int dir = 2;
    int cnt_stop = 0;
    bool stop = false;
    vector<int> idx_task(m);

    rep(_,300) {
        // 人間
        string move_human;
        if (prepar1) {
            rep(man,m) {  
                move_human += f1(man, hx[man], hy[man], goal1[man].first, goal1[man].second);
                if (hx[man] == goal1[man].first && hy[man] == goal1[man].second) {
                    prepar1_done_set.insert(man);
                }
                if (prepar1_done_set.size() == m) prepar1 = false;
            }
        } else if (wall) {
            rep(man,m) {
                if (man == 0) {
                    if (idx_task[man] == task2.size()) {
                        move_human += '.';
                        wall_done_set.insert(man);
                    }
                    else {
                        int id = task2[idx_task[man]].first;
                        int dir = task2[idx_task[man]].second;
                        if (id == 0) {
                            move(move_human, man, dir);
                            idx_task[man]++;
                        } else {
                            int ni = hx[man]+di[dir], nj = hy[man]+dj[dir];
                            if (petok(ni,nj)) {
                                build(move_human, man, dir);
                                idx_task[man]++;
                            } else {
                                move_human += '.';
                            }
                        }
                    }
                } else if (man < 5) {
                    if (idx_task[man] == task1.size()) {
                        move_human += '.';
                        wall_done_set.insert(man);
                    }
                    else {
                        int id = task1[idx_task[man]].first;
                        int dir = task1[idx_task[man]].second;
                        if (id == 0) {
                            move(move_human, man, dir);
                            idx_task[man]++;
                        } else {
                            int ni = hx[man]+di[dir], nj = hy[man]+dj[dir];
                            if (petok(ni,nj)) {
                                build(move_human, man, dir);
                                idx_task[man]++;
                            } else {
                                move_human += '.';
                            }
                        }
                    }
                } else {
                    move_human += '.';
                }
                if (wall_done_set.size() == 5) wall = false;
            }
        } else if (close_dog) {
            bool dog_out = false;
            bool dog_aaa = true;
            
            rep(pet,n) {
                if (pt[pet] == 4) {
                    dog_out = true;
                    if (where_room(px[pet], py[pet]) != 5) dog_aaa = false;
                }
            }
            
            if (dog_out) { // 犬いる
                int decoi; // おとり
                if (m == 5) decoi = 0;
                else decoi = 5;
                set<int> goal_man;
                rep(man,m) {
                    int i = hx[man], j = hy[man];
                    if (pre_nodog) {
                        if (man == decoi) {
                            move_human += f1(man, hx[man], hy[man], 17, 29);
                            if (hx[man] == 17 && hy[man] == 29) {
                                goal_man.insert(man);
                            }
                        } else {
                            move_human += f1(man, hx[man], hy[man], 16, left_col);
                            if (hx[man] == 16 && hy[man] == left_col) {
                                goal_man.insert(man);
                            }
                        }
                    } else {
                        if (man != decoi && G1[i][j+1] != -1 && petok(i,j+1) && dog_aaa) {
                            build(move_human, man, 3);
                            close_dog = false;
                        } else {
                            move_human += '.';
                        }
                    }
                }
                if (goal_man.size() == m) pre_nodog = false;
            } else { // 犬いない
                rep(man,m) {
                    move_human += '.';
                }
                close_dog = false;
            }
        } else {
            vector<int> cnt_pet(11);
            rep(pet,n) {
                cnt_pet[where_room(px[pet], py[pet])]++;
            }
            rep(man,m) {
                int i = hx[man], j = hy[man];
                if (P(i,j) != close_point[man%5]) {
                    move_human += f1(man, hx[man], hy[man], close_point[man%5].first, close_point[man%5].second);
                } else {
                    if (G1[i-1][j] != -1 && petok(i-1,j) && cnt_pet[(i-1)/3]) {
                        build(move_human, man, 0);
                        open_room.erase((i-1)/3);
                    } else if (G1[i+1][j] != -1 && petok(i+1,j) && cnt_pet[(i+1)/3]) {
                        build(move_human, man, 2);
                        open_room.erase((i+1)/3);
                    } else {
                        move_human += '.';
                    }
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