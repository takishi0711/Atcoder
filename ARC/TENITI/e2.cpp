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

int k;
string s;
dsu d(500005);
bool dame = false;

void f(int level, string t) {
    int sz = t.size();
    if (sz == 0) {
        if (level == 0) return;
        else {
            dame = true;
            return;
        }
    }
    if (level == 0) {
        if (sz == 1) {
            dame = true;
        } 
        return;
    }
    if (sz == 1) {
        if (level != 1) dame = true;
        return;
    }
    if (sz%2 == 1) {
        int l = sz/2-1, r = sz/2+1;
        while (1) {
            d.merge(l, r);
            l--; r++;
            if (l < 0) {
                f(level-1, t.substr(0,sz/2));
                return;
            }            
        }
    } else {
        int l = sz/2-1, r = sz/2;
        while (1) {
            d.merge(l, r);
            l--; r++;
            if (l < 0) {
                f(level-1, t.substr(0,sz/2));
                return;
            }            
        }
    }
}

int main() {
    cin >> k >> s;
    f(k, s);
    if (dame) {
        cout << "impossible" << endl;
        return 0;
    }
    int n = s.size();
    vector<vector<int>> cntalph(n+1, vector<int>());
    rep(i,n) {
        int x = d.leader(i);
        cntalph[x].push_back(i);
    }
    rep(i,n) {
        if (cntalph[i].size() == 0) continue;
        rep(j,cntalph[i].size()) cout << s[cntalph[i][j]] << " ";
        cout << endl;
    }
    int ans = 0;
    rep(i,n) {
        if (cntalph[i].size() == 0) continue;
        else {
            int m = cntalph[i].size();
            vector<int> aaa(26);
            int mx = 0;
            rep(j,m) {
                aaa[s[cntalph[i][j]]-'a']++;
                mx = max(mx, aaa[s[cntalph[i][j]]-'a']);
            }
            ans += m-mx;
        }
    }
    cout << ans << endl;
    return 0;
}