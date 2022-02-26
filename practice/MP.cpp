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

vector<int> f(vector<int>& a) {
    int n = a.size();
    vector<int> res(n);
    rep(i,n) res[i] = a[i]^a[(i+1)%n];
    return res;
}

// Morris-Pratt
template<typename T>
struct MP {
    int n;
    T t;
    vector<int> a;
    MP() {}
    MP(const T& t): t(t) {
        n = t.size();
        a = vector<int>(n+1);
        a[0] = -1;
        int j = -1;
        for (int i = 0; i < n; ++i) {
            while (j != -1 && t[j] != t[i]) j = a[j];
            j++;
            a[i+1] = j;
        }
    }
    int operator[](int i) { return a[i];}
    vector<int> findAll(const T& s) {
        vector<int> res;
        int j = 0;
        for (int i = 0; i < s.size(); ++i) {
            while (j != -1 && t[j] != s[i]) j = a[j];
            j++;
            if (j == n) {
                res.push_back(i-j+1);
                j = a[j];
            }
        }
        return res;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    vector<int> xa = f(a);
    vector<int> xb = f(b);
    MP<vector<int>> mp(xa);
    xb.insert(xb.end(), xb.begin(), xb.end());
    vector<int> res = mp.findAll(xb);
    vector<int> ks;
    for (int p : res) ks.push_back(n-p);
    sort(ks.begin(), ks.end());
    for (int k : ks) {
        if (k >= n) continue;
        int x = a[k]^b[0];
        printf("%d %d\n", k, x);
    }
    return 0;
}