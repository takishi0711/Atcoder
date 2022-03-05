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
    vector<int> a(n), b(n);
    multiset<int> ast, bst;
    vector<int> acnt(5005);
    bool dob = false;
    rep(i,n) {
        cin >> a[i];
        ast.insert(a[i]);
        acnt[a[i]]++;
        if (acnt[a[i]] > 1) dob = true;
    }
    rep(i,n) {
        cin >> b[i];
        bst.insert(b[i]);
    }
    if (ast != bst) {
        cout << "No" << endl;
        return 0;
    }
    if (dob) {
        cout << "Yes" << endl;
        return 0;
    }
    fenwick_tree<int> f1(5005), f2(5005);
    int tentoua = 0, tentoub = 0;
    rep(i,n) {
        tentoua += f1.sum(0,5001) - f1.sum(0,a[i]+1);
        tentoua += f2.sum(0,5001) - f2.sum(0,b[i]+1);
        f1.add(a[i],1);
        f2.add(b[i],1);
    }
    if (tentoua%2 == tentoub%2) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}