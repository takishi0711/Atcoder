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

// ARC120 C Swaps 2

vector<int> compress1(vector<int>& v, int n) {
    vector<int> dic;
    rep(i,n) dic.push_back(v[i]);
    sort(dic.begin(), dic.end());
    dic.erase(unique(dic.begin(), dic.end()), dic.end());
    rep(i,n) v[i] = lower_bound(dic.begin(), dic.end(), v[i]) - dic.begin();
    return dic;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    rep(i,n) {
        cin >> a[i];
        a[i] += i;
    }
    rep(i,n) {
        cin >> b[i];
        b[i] += i;
    }
    vector<int> check_a, check_b;
    check_a = a;
    check_b = b;
    sort(check_a.begin(), check_a.end());
    sort(check_b.begin(), check_b.end());
    if (check_a != check_b) {
        cout << -1 << endl;
        return 0;
    }
    compress1(a, n);
    compress1(b, n);
    vector<deque<int>> vec(n);
    rep(i,n) vec[a[i]].push_back(i);
    rep(i,n) {
        int idx = vec[b[i]][0];
        vec[b[i]].pop_front();
        a[idx] = i;
    }
    fenwick_tree<int> ft(n);
    ll ans = 0;
    rep(i,n) {
        ans += i - ft.sum(0,a[i]);
        ft.add(a[i], 1);
    }
    cout << ans << endl;
    return 0;
}