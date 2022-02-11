#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y);
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};
const int INF = 1001001001;

int main() {
    int n;
    cin >> n;
    map<int,int> mpa, mpb;
    vector<int> a(n), b(n);
    rep(i,n) {
        cin >> a[i];
        mpa[a[i]]++;
    }
    rep(i,n) {
        cin >> b[i];
        mpb[b[i]]++;
    }
    for (auto x : mpa) {
        int i = x.first;
        int j = x.second;
        if (mpb[i] > n-j) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    int bj = n-1;
    int bh = 0;
    vector<bool> bok(n, false);
    rep(i,n) {
        if (bok[bj]) {
            bh = bj;
            while (bok[bj]) {
                bj--;
            }
            printf("%d ", b[bj]);
            bok[bj] = true;
            bj = bh;
        }
        else if (a[i] != b[bj]) {
            printf("%d ", b[bj]);
            bok[bj] = true;
            bj--;
            continue;
        }
        else {
            bh = bj;
            while (b[bj] == a[i]) {
                bj--;
            }
            printf("%d ", b[bj]);
            bok[bj] = true;
            bj = bh;
        }
    }
    cout << endl;
    return 0;
}