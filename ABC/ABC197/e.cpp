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

vector<ll> num[200005];

int main() {
    int n;
    cin >> n;
    set<int> st;
    vector<int> cnt(200005);
    rep(i,n) {
        ll x;
        int c;
        cin >> x >> c;
        cnt[c]++;
        st.insert(c);
        num[c].push_back(x);
    }
    for (int c : st) {
        if (cnt[c] == 1) continue;
        sort(num[c].begin(), num[c].end());
    }
    
    return 0;
}