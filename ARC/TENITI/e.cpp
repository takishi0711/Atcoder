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
bool kai0 = false;
int kaisz = 0;

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
        } else {
            kai0 = true;
            kaisz = sz;
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
    int ans = 0;
    string las;
    rep(i,kaisz) las += 'a';
    vector<int> secon(n);
    rep(i,n) {
        if (cntalph[i].size() == 0) continue;
        else {
            int m = cntalph[i].size();
            vector<int> aaa(26);
            int mx = 0;
            bool g = false;
            char mm;
            int dd = 0;
            rep(j,m) {
                
                aaa[s[cntalph[i][j]]-'a']++;
                mx = max(mx, aaa[s[cntalph[i][j]]-'a']);
                if (mx == cntalph[i][j]) mm = s[cntalph[i][j]];
                if (0 <= cntalph[i][j] && cntalph[i][j] < kaisz) {
                    g = true;
                    dd = cntalph[i][j];
                }
            }
            vector<int> cnt2;
            rep(j,26) {
                if (aaa[i]) cnt2.push_back(aaa[i]);
            }
            sort(cnt2.rbegin(), cnt2.rend());
            if (cnt2.size() >= 2) {
                secon[i] = cnt2[1];
            }
            if (g) {
                las[dd] = mm;
            }
            ans += m-mx;
        }
    }
    string las2 = las;
    reverse(las2.begin(), las2.end());
    if (las == las2) {
        
    }
    cout << ans << endl;
    return 0;
}