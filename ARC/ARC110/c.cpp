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
    vector<int> p(n+1);
    for (int i = 1; i <= n; i++) cin >> p[i];
    vector<int> t(n+1);
    for (int i = 1; i <= n; i++) {
        t[i] = p[i]-i;
    }
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        if (t[i] > 0) sum += t[i];
        if (t[i] == 0) {
            cout << -1 << endl;
            return 0;
        }
    }
    if (sum != n-1) {
        cout << -1 << endl;
        return 0;
    }
    stack<int> st;
    for (int i = n; i >= 1; i--) {
        if (t[i] < 0) {
            if (i != n) st.push(i);
        }
        else cout << i << endl;
    }
    while (!st.empty()) {
        int x = st.top(); st.pop();
        cout << x << endl;
    }
    return 0;
}