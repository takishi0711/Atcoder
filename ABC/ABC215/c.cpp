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
    string s;
    cin >> s;
    int k;
    cin >> k;
    int n = s.size();
    vector<int> v(n);
    rep(i,n) {
        v[i] = s[i]-'a';
    }
    sort(v.begin(), v.end());
    vector<string> st;
    do {
        string ss;
        rep(i,n) {
            ss += 'a'+v[i];
        }
        st.push_back(ss);
    } while (next_permutation(v.begin(), v.end()));
    sort(st.begin(), st.end());
    st.erase(unique(st.begin(), st.end()), st.end());
    cout << st[k-1] << endl;
    return 0;
}