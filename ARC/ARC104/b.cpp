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



int main() {
    int n;
    string s;
    cin >> n >> s;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        map<char,int> mp;
        for (int j = i; j < n; j++) {
            mp[s[j]]++;
            if (mp['A'] == mp['T'] && mp['C'] == mp['G']) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}