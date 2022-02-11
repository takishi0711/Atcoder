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

vector<int> alph(26);
vector<bool> a(26);
vector<int> b;
vector<string> s(3);
vector<bool> used(10);

ll calc(string s) {
    int n = s.size();
    ll res = 0;
    rep(i,n) {
        res *= 10;
        res += alph[s[i]-'a'];
    }
    return res;
}

void dfs(int num) {
    if (num >= b.size()) {
        if (calc(s[0])+calc(s[1]) == calc(s[2])) {
            cout << calc(s[0]) << endl;
            cout << calc(s[1]) << endl;
            cout << calc(s[2]) << endl;
        }
    }

} 

int main() {
    
    rep(i,3) cin >> s[i];
    int cnt = 0;
    rep(i,3) {
        rep(j,s[i].size()) {
            int x = s[i][j]-'a';
            if (a[x] == false) {
                cnt++;
                a[x] = true;
                b.push_back(x);
            }  
        }
    }
    if (cnt > 10) {
        cout << "UNSOLVABLE" << endl;
        return 0;
    }
    dfs(0);
    return 0;
}