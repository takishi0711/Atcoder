#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y);
#define chmin(x,y) x = min(x,y);
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};
const int INF = 1001001001;
const ll LINF = 1001002003004005006ll;
const double PI = acos(-1);

vector<int> to[200005];

vector<int> match(200005);
vector<bool> visited(200005);
vector<bool> _visited(200005);
int start = 0;
bool ok = false;

string kekka(int x) {
    if (x == 0) return "Takahashi";
    if (x == -1) return "Draw";
    if (x == 1) return "Aoki";
}

int dfs(int v) {
    if (visited[v]) return match[v];
    if (to[v].size() == 0) {
        visited[v] = true;
        return match[v] = 0;
    }
    
    if (_visited[v]) {
        if (start == v) {
            if (ok) return -1;
            ok = true; 
        } else {
            return -1;
        }
    } 
    _visited[v] = true;

    match[v] = INF;
    for (int u : to[v]) {
        int resu = dfs(u);
        if (match[v] == INF) {
            if (resu == 0) match[v] = 1;
            if (resu == 1) match[v] = 0;
            if (resu == -1) match[v] = -1;
        } else {
            if (match[v] == 1) continue;
            if (match[v] == 0) {
                if (resu == 0) match[v] = 1;
                if (resu == -1) match[v] = -1;
            }
            if (match[v] == -1) {
                if (resu == 0) match[v] = 1;
            }
        }
    }
    visited[v] = true;
    return match[v];
}

int main() {
    int n;
    cin >> n;
    vector<string> s(n), stin(n), stout(n);
    map<string, vector<int>> in;
    map<string, vector<int>> out;
    rep(i,n) {
        cin >> s[i];
        stin[i] = s[i].substr(0,3);
        stout[i] = s[i].substr(int(s[i].size())-3);
        in[stin[i]].push_back(i);
        out[stout[i]].push_back(i);
    }
    rep(i,n) {
        for (int u : in[stout[i]]) {
            to[i].push_back(u);
        }
    }
    rep(i,n) {
        //_visited = vector<bool>(200005, false); 
        start = i;
        cout << kekka(dfs(i)) << endl;
    }
    return 0;
}