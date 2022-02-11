#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define int ll
using VI = vector<int>;
using PII = pair<int, int>;

#define FOR(i, a, n) for (ll i = (ll)a; i < (ll)n; ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(x) x.begin(), x.end()
#define PB push_back

signed main(void)
{

    vector<string> s(3);
    REP(i, 3) cin >> s[i];

    // 座圧しておく
    vector<char> v;
    REP(i, 3) REP(j, s[i].size()) v.PB(s[i][j]);
    sort(ALL(v)); v.erase(unique(ALL(v)), v.end());
    REP(i, 3) REP(j, s[i].size()) s[i][j] = lower_bound(ALL(v), s[i][j]) - v.begin() + 'A';

    // leading-zero対策
    vector<bool> fro(3, false);
    REP(i, 3) if(s[i].size() >= 2) fro[s[i][0]-'A'] = true;

    // 係数を求める
    VI a(15, 0);
    REP(i, 3) {
        for(int j=s[i].size()-1, tmp=1; j>=0; --j, tmp*=10) {
        if(i == 3-1) a[s[i][j]-'A'] -= tmp;
        else a[s[i][j]-'A'] += tmp;
        }
    }

    map<PII, int> mp1, mp2;
    int m = v.size(), m2 = m/2;

    function<void(int,int,int)> dfs1 = [&](int x, int sum, int used) {
        if(x == m2) {mp1[{sum, used}]++; return;}
        REP(i, 10) {
        // leading-zeroとかすでに使ってる数は使えない
        if(fro[x] && i==0) continue;
        if(used&1<<i) continue;
        dfs1(x+1, sum+i*a[x], used | 1<<i);
        }
    };

    function<void(int,int,int)> dfs2 = [&](int x, int sum, int used) {
        if(x == m) {mp2[{sum, used}]++; return;}
        REP(i, 10) {
        if(fro[x] && i==0) continue;
        if(used&1<<i) continue;
        dfs2(x+1, sum+i*a[x], used | 1<<i);
        }
    };

    // 列挙
    dfs1(0, 0, 0);
    dfs2(m2, 0, 0);

    vector<pair<PII, int>> vec1(ALL(mp1)), vec2(ALL(mp2));

    for(auto &i: vec2) i.first.first *= -1;

    // 尺取りをする
    int ans = 0;
    int l = 0, r = vec2.size()-1;
    for(;l<vec1.size();) {
        while(r > 0 && vec1[l].first.first > vec2[r].first.first) r--;
        int val1 = vec1[l].first.first, val2 = vec2[r].first.first;
        // 合計が0にならないならcontinue
        if(val1 != val2) {
        while(l < vec1.size() && vec1[l].first.first==val1) l++;
        continue;
    }
    // 合計が0になるような組み合わせを全て見て使ってる数が被っていなければ答えにプラス
    for(int i=l; i<vec1.size() && vec1[i].first.first==val1; ++i) {
    for(int j=r; j>=0 && vec2[j].first.first==val2; --j) {
        if((vec1[i].first.second&vec2[j].first.second) == 0) {
        ans += vec1[i].second * vec2[j].second;
        }
    }
    }
    while(l < vec1.size() && vec1[l].first.first==val1) l++;
    cout << ans << endl;
  }

  return 0;
}