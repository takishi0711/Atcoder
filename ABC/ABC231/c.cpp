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



int main() {
    int n, q;
    cin >> n >> q;
    set<int> st;
    vector<int> vec;
    map<int,int> mp;
    rep(i,n) {
        int a;
        cin >> a;
        st.insert(a);
        mp[a]++;
    }
    auto it = st.rbegin();
    for (int x : st) vec.push_back(x);
    int m = vec.size();
    for (int i = m-1; i > 0; i--) {
        mp[vec[i-1]] += mp[vec[i]];
    }
    rep(qi,q) {
        int x;
        cin >> x;
        int idx = lower_bound(vec.begin(), vec.end(), x) - vec.begin();
        if (idx == m) cout << 0 << endl;
        else cout << mp[vec[idx]] << endl;
    }
    return 0;
}