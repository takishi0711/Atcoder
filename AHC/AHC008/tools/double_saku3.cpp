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
vector<P> task[5];
vector<P> close_point(15);
bool prepar;
bool wall = true;
bool close_dog;
set<int> prepar_done_set;
vector<bool> prepar1_done(15);
vector<bool> wall_done(15);
vector<bool> prepar_dog_done(15);
vector<bool> prepar_close_done(15);
set<int> wall_done_set;
int dir = 2;
int cnt_stop = 0;
bool stop = false;
vector<int> man_task(15);
vector<int> idx_task(15);
bool dog_exist;
vector<P> goal1(15);
vector<P> goal_dog(15);
vector<P> goal_close(15);
map<P, P> close_point_pair;
map<P, bool> close_point_exist;
set<P> prev_man_pos;
vector<P> order_three[2];

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
    if (prev_man_pos.count(P(i,j))) return false;
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
    G2[hx[man]][hy[man]]--;
    hx[man] += di[dir];
    hy[man] += dj[dir];
    G2[hx[man]][hy[man]]++;
}

// 柵を dir 方向に建てる
void build(string& move_human, int man, int dir) {
    move_human += dir_to_c2(dir);
    int ni = hx[man]+di[dir], nj = hy[man]+dj[dir];
    G1[ni][nj] = -1;
    G2[ni][nj] = -1;
}

void make_task0() {
    rep(i,13) {
        task[0].push_back(P(0,1));
        task[0].push_back(P(1,3));
    }   
    task[0].push_back(P(0,0));
    task[0].push_back(P(1,2));
    rep(i,2) {
        task[0].push_back(P(0,0));
    }
    rep(i,14) {
        task[0].push_back(P(0,3));
        task[0].push_back(P(1,1));
    }
    rep(i,3) {
        task[0].push_back(P(0,3));
    }
    rep(i,12) {
        task[0].push_back(P(0,3));
        task[0].push_back(P(1,1));
    }
    task[0].push_back(P(0,2));
    task[0].push_back(P(1,0));
    rep(i,2) {
        task[0].push_back(P(0,2));
    }
    rep(i,13) {
        task[0].push_back(P(0,1));
        task[0].push_back(P(1,3));
    }
}

void make_task1() {
    task[1].push_back(P(1,1));
    task[1].push_back(P(1,3));
    task[1].push_back(P(0,2));
    rep(i,9) {
        task[1].push_back(P(1,1));
        task[1].push_back(P(1,3));
        task[1].push_back(P(0,2));
        task[1].push_back(P(0,2));
        task[1].push_back(P(0,2));
    }
    task[1].push_back(P(1,1));
    task[1].push_back(P(1,3));
    task[1].push_back(P(0,0));

    rep(i,15) {
        task[1].push_back(P(0,1));
    }

    rep(i,14) {
        task[1].push_back(P(0,3));
        task[1].push_back(P(1,1));
    }   
    rep(i,3) {
        task[1].push_back(P(0,3));
    }
    rep(i,12) {
        task[1].push_back(P(0,3));
        task[1].push_back(P(1,1));
    }
    task[1].push_back(P(0,2));
    task[1].push_back(P(1,0));
}

void make_task2() {
    rep(i,14) {
        task[2].push_back(P(1,1));
        task[2].push_back(P(1,3));
        task[2].push_back(P(0,2));
        task[2].push_back(P(0,2));
    }
    task[2].push_back(P(1,1));
    task[2].push_back(P(1,3));
    task[2].push_back(P(0,2));
}

// タスクを実行
void do_task(int man, string& move_human) {
    if (idx_task[man] == task[man_task[man]].size()) {
        move_human += '.';
        wall_done[man] = true;
    }
    else {
        int id = task[man_task[man]][idx_task[man]].first;
        int dir = task[man_task[man]][idx_task[man]].second;
        int ni = hx[man]+di[dir], nj = hy[man]+dj[dir];
        if (id == 0) {
            if (G1[ni][nj] != -1) {
                move(move_human, man, dir);
                idx_task[man]++;
            } else {
                move_human += '.';
            }
        } else {
            if (petok(ni,nj)) {
                build(move_human, man, dir);
                idx_task[man]++;
            } else {
                move_human += '.';
            }
        }
    }    
}

// ペットの位置を分類
int where_room(int i, int j) {
    if (j <= 13) {
        return i/3;
    } else if (j <= 16) {
        return 20;
    } else {
        return (i/3)+10;
    }
}



int main() {
    // 初期入力
    cin >> n;
    rep(i,n) {
        cin >> px[i] >> py[i] >> pt[i];
        if (pt[i] == 4) dog_exist = true;
        px[i]--; py[i]--;
        G1[px[i]][py[i]]++;
    }
    cin >> m;
    rep(i,m) {
        cin >> hx[i] >> hy[i];
        hx[i]--; hy[i]--;
        G2[hx[i]][hy[i]]++;
    }
    
    make_task0();
    make_task1();
    make_task2();
    
    close_point[0] = P(29, 15);
    close_point[1] = P(20, 15);
    close_point[2] = P(11, 15);
    close_point[3] = P(5, 15);
    close_point[4] = P(14, 15);
    close_point[5] = P(23, 15);
    close_point[6] = P(8, 15);
    close_point[7] = P(2, 15);
    close_point[8] = P(26, 15);
    close_point[9] = P(17, 15);
    close_point_pair[close_point[0]] = close_point[8]; close_point_pair[close_point[8]] = close_point[0]; 
    close_point_pair[close_point[1]] = close_point[9]; close_point_pair[close_point[9]] = close_point[1]; 
    close_point_pair[close_point[2]] = close_point[6]; close_point_pair[close_point[6]] = close_point[2]; 
    close_point_pair[close_point[3]] = close_point[7]; close_point_pair[close_point[7]] = close_point[3]; 
    int pos = 0;
    if (dog_exist) {
        rep(i,m) {
            if (i == 4) continue;
            goal_close[i] = close_point[pos];
            close_point_exist[close_point[pos]] = true;
            pos++;
        }
    } else {
        rep(i,m) {
            goal_close[i] = close_point[pos];
            close_point_exist[close_point[pos]] = true;
            pos++;
        }
    }
    order_three[0] = {close_point[8], close_point[5], close_point[8], close_point[0]};
    order_three[1] = {close_point[9], close_point[4], close_point[9], close_point[1]};
    
    goal1[0] = P(6,13);
    goal1[1] = P(12,13);
    goal1[2] = P(18,13);
    goal1[3] = P(24,13);
    goal1[4] = P(0,15);
    for (int i = 5; i < m; i++) {
        goal1[i] = P(28,29);
    }

    rep(i,m) {
        if (i == 4) goal_dog[i] = P(28,29);
        else goal_dog[i] = P(29,15);
    }

    man_task[0] = 0;
    man_task[1] = 0;
    man_task[2] = 0;
    man_task[3] = 0;
    man_task[4] = 1;
    for (int i = 5; i < m; i++) {
        man_task[i] = -1; 
    }
    
    // cout << "#" << endl;
    rep(_,300) {
        // 人間
        string move_human;
        prev_man_pos.clear();
        rep(man,m) {
            prev_man_pos.insert(P(hx[man],hy[man]));
        } 
        if (prepar == false) {
            rep(man,m) {  
                if (prepar1_done[man] == false) { // 最初の定位置へ
                    move_human += f1(man, hx[man], hy[man], goal1[man].first, goal1[man].second);
                    if (hx[man] == goal1[man].first && hy[man] == goal1[man].second) {
                        prepar1_done[man] = true;
                    }
                } else if (wall_done[man] == false) { // 壁を建設
                    if (man_task[man] == -1) {
                        move_human += '.';
                        wall_done[man] = true;
                    } else {
                        do_task(man, move_human);
                    }                    
                } else { // 犬がいるならおとり用の定位置へ
                    if (dog_exist && prepar_dog_done[man] == false) {
                        move_human += f1(man, hx[man], hy[man], goal_dog[man].first, goal_dog[man].second);
                        if (hx[man] == goal_dog[man].first && hy[man] == goal_dog[man].second) {
                            prepar_dog_done[man] = true;
                        }
                    } else {
                        prepar_done_set.insert(man);
                        move_human += '.';
                    }
                }
            }
            if (prepar_done_set.size() == m) prepar = true;
        } else if (dog_exist && close_dog == false) { // おとりを使って犬を捕まえる
        bool dog_in_room = true;
            rep(pet,n) {
                if (pt[pet] == 4) {
                    if (where_room(px[pet], py[pet]) != 19) dog_in_room = false;
                }
            }
            rep(man,m) {
                int i = hx[man], j = hy[man];
                if (man != 4 && G1[i][j+1] != -1 && petok(i,j+1) && dog_in_room) {
                    build(move_human, man, 3);
                    close_dog = true;
                } else {
                    move_human += '.';
                }                
            }            
        } else { // 最後の壁を建設
            vector<int> cnt_pet(25);
            rep(pet,n) {
                cnt_pet[where_room(px[pet], py[pet])]++;
            }
            vector<int> cnt_man(25);
            rep(man,m) {
                cnt_pet[where_room(hx[man], hy[man])]++;
            }
            rep(man,m) {
                int i = hx[man], j = hy[man];
                if (dog_exist && man == 4) {
                    move_human += '.';
                } else if (P(i,j) != goal_close[man]) {
                    move_human += f1(man, hx[man], hy[man], goal_close[man].first, goal_close[man].second);
                } else {
                    if (G1[i][j-1] != -1 && petok(i,j-1) && cnt_pet[i/3] && !cnt_man[i/3]) {
                        build(move_human, man, 1);
                    } else if (G1[i][j+1] != -1 && petok(i,j+1) && cnt_pet[i/3 + 10] && !cnt_man[i/3 + 10]) {
                        build(move_human, man, 3);
                    } else if (man == 0) {
                        move_human += '.';
                        if (close_point_exist[close_point[5]]) {
                            if (!close_point_exist[close_point_pair[goal_close[man]]]) {
                                int pi = close_point_pair[goal_close[man]].first, pj = close_point_pair[goal_close[man]].second;
                                if (G1[pi][pj-1] != -1 || G1[pi][pj+1] != -1) {
                                    close_point_exist[goal_close[man]] = false;
                                    goal_close[man] = close_point_pair[goal_close[man]]; 
                                }
                            }
                        } else {
                            vector<P> order_three_nex;
                            rep(i,order_three[man].size()) {
                                int pi = order_three[man][i].first, pj = order_three[man][i].second;
                                if (G1[pi][pj-1] != -1 || G1[pi][pj+1] != -1) order_three_nex.push_back(order_three[man][i]);
                            }
                            if (order_three_nex.size() > 0) {
                                goal_close[man] = order_three_nex[0];
                                rotate(order_three_nex.begin(), order_three_nex.begin()+1, order_three_nex.end());
                            }
                            order_three[man] = order_three_nex;
                        }
                    } else if (man == 1) {
                        move_human += '.';
                        if (close_point_exist[close_point[4]]) {
                            if (!close_point_exist[close_point_pair[goal_close[man]]]) {
                                int pi = close_point_pair[goal_close[man]].first, pj = close_point_pair[goal_close[man]].second;
                                if (G1[pi][pj-1] != -1 || G1[pi][pj+1] != -1) {
                                    close_point_exist[goal_close[man]] = false;
                                    goal_close[man] = close_point_pair[goal_close[man]]; 
                                }
                            }
                        } else {
                            vector<P> order_three_nex;
                            rep(i,order_three[man].size()) {
                                int pi = order_three[man][i].first, pj = order_three[man][i].second;
                                if (G1[pi][pj-1] != -1 || G1[pi][pj+1] != -1) order_three_nex.push_back(order_three[man][i]);
                            }
                            if (order_three_nex.size() > 0) {
                                goal_close[man] = order_three_nex[0];
                                rotate(order_three_nex.begin(), order_three_nex.begin()+1, order_three_nex.end());
                            }
                            order_three[man] = order_three_nex;
                        }
                    } else if (man == 2 || man == 3) {
                        move_human += '.';
                        if (!close_point_exist[close_point_pair[goal_close[man]]]) {
                            int pi = close_point_pair[goal_close[man]].first, pj = close_point_pair[goal_close[man]].second;
                            if (G1[pi][pj-1] != -1 || G1[pi][pj+1] != -1) {
                                close_point_exist[goal_close[man]] = false;
                                goal_close[man] = close_point_pair[goal_close[man]]; 
                            }
                        }
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