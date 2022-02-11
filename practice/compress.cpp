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

// 第二回日本最強プログラマー学生選手権

// 座標圧縮
vector<int> compress1(vector<int>& v, int n) {
    vector<int> dic;
    rep(i,n) dic.push_back(v[i]);
    sort(dic.begin(), dic.end());
    dic.erase(unique(dic.begin(), dic.end()), dic.end());
    rep(i,n) v[i] = lower_bound(dic.begin(), dic.end(), v[i]) - dic.begin();
    return dic;
}

vector<int> T(200005), X(200005), Y(200005);
//int T[200005], X[200005], Y[200005];

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    rep(i,q) cin >> T[i] >> X[i] >> Y[i];

    auto ZY = compress1(Y, q+1);
    fenwick_tree<ll> Acnt(200005), Bcnt(200005);
    fenwick_tree<ll> Atot(200005), Btot(200005);
    Acnt.add(0,n);
    Bcnt.add(0,m);
    
    vector<int> A(200005,0), B(200005,0);
    ll ans = 0;
    rep(i,q) {
        if (T[i] == 1) {
            int x = X[i]-1;
            int y = Y[i];
            ans -= Bcnt.sum(0, A[x]+1) * ZY[A[x]];
            ans -= Btot.sum(A[x]+1, 200004);

            Acnt.add(A[x], -1);
            Atot.add(A[x], -ZY[A[x]]);

            A[x] = y;

            ans += Bcnt.sum(0, A[x]+1) * ZY[A[x]];
            ans += Btot.sum(A[x]+1, 200004);

            Acnt.add(A[x], 1);
            Atot.add(A[x], ZY[A[x]]);
        } else {
            int x = X[i]-1;
            int y = Y[i];
            ans -= Acnt.sum(0, B[x]+1) * ZY[B[x]];
            ans -= Atot.sum(B[x]+1, 200004);

            Bcnt.add(B[x], -1);
            Btot.add(B[x], -ZY[B[x]]);

            B[x] = y;

            ans += Acnt.sum(0, B[x]+1) * ZY[B[x]];
            ans += Atot.sum(B[x]+1, 200004);

            Bcnt.add(B[x], 1);
            Btot.add(B[x], ZY[B[x]]);
        }
        cout << ans << endl;
    }
    return 0;
}