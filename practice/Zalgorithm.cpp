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
    string s;
    cin >> s;
    int ans = 0;
    rep(q,n) {
        string S = s.substr(q);
        vector<int> A(S.size());
        A[0] = S.size();
        int i = 1, j = 0;
        while (i < S.size()) {
            while (i+j < S.size() && S[j] == S[i+j]) ++j;
            A[i] = j;
            if (j == 0) { ++i; continue;}
            int k = 1;
            while (i+k < S.size() && k+A[k] < j) A[i+k] = A[k], ++k;
            i += k; j -= k;
        }
        int now = 0;
        rep(k,A.size()) {
            now = min(k,A[k]);
            ans = max(ans, now);
        }
    }
    cout << ans << endl;
    return 0;
}