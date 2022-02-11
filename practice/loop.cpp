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

int f(int x) {
    int res = x;
    string s = to_string(x);
    rep(i,s.size()) res += s[i]-'0';
    return res%100000;
}

int main() {
    ll n, k;
    cin >> n >> k;
    vector<int> vec, id(100005, -1);
    int len = 0;
    while (id[n] == -1) {
        vec.push_back(n);
        id[n] = len;
        n = f(n);
        len++;
    }
    int c = len-id[n];
    k -= id[n];
    k = k%c;
    int ans = vec[id[n]+k];
    cout << ans << endl;
    return 0;
}