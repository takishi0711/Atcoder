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
    int n;
    cin >> n;
    vector<int> cnt(n+1);
    set<int> st;
    for (int i = 1; i <= n; i++) st.insert(i);
    rep(i,4*n-1) {
        int a;
        cin >> a;
        cnt[a]++;
        if (cnt[a] == 4) {
            st.erase(a);
        }
    }
    cout << *st.begin() << endl;
    return 0;
}