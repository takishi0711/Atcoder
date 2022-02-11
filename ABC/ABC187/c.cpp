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



int main() {
    int n;
    cin >> n;
    map<string,int> mp;
    rep(i,n) {
        string s;
        cin >> s;
        mp[s]++;
    }
    for (auto p : mp) {
        if (p.first[0] == '!') continue;
        string t = 't' + p.first;
        if (mp[t] > 0) {
            cout << p.first << endl;
            return 0;
        }
    }
    cout << "satisfiable" << endl;
    return 0;
}