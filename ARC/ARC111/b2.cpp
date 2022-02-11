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
    vector<int> a(n), b(n);
    deque<int> q;
    vector<int> cnt(400005);
    rep(i,n) {
        cin >> a[i] >> b[i];
        if (a[i] == b[i]) q.push_front(i);
        else {
            q.push_back(i);
            cnt[a[i]]++; cnt[b[i]]++;
        }
    }
    int ans = 0;
    for (int i = 1; i <= 400000; i++) {
        if (cnt[i] >= 2) ans++;
    }
    cout << ans << endl;
    return 0;
}