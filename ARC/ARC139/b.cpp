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

namespace utility {
    struct timer {
        chrono::system_clock::time_point start;

        // 開始時間を記録
        void CodeStart() {
            start = chrono::system_clock::now();
        }

        // 経過時間 (s) を返す
        double elapsed() const {
            using namespace std::chrono;
            return (double)duration_cast<milliseconds>(system_clock::now() - start).count()/1000;
        }
    } mytm;
}

struct st {
    ll add;
    ll bunshi, bunbo;
    st() : add(0), bunshi(1), bunbo(1) {};
    st(ll add_, ll bunshi_, ll bunbo_) : add(add_), bunshi(bunshi_), bunbo(bunbo_) {};
    bool operator<(const st& s) const {
        return bunshi * s.bunbo < s.bunshi * bunbo;
    }
};

int main() {
    utility::mytm.CodeStart();
    int t;
    cin >> t;
    rep(ti,t) {
        ll N, a, b, x, y, z;
        cin >> N >> a >> b >> x >> y >> z;
        vector<st> vec;
        vec.push_back(st(1, x, 1));
        vec.push_back(st(a, y, a));
        vec.push_back(st(b, z, b));
        sort(vec.begin(), vec.end());
        ll ans = 0;
        ll n = N;
        vector<ll> cnt(3);
        rep(i,3) {
            cnt[i] = n/vec[i].add;
            ans += vec[i].bunshi * cnt[i];
            n = n%vec[i].add;
        }

        if (vec[2].add == 1) {
            ll x = N - cnt[0]*vec[0].add;
            ll now = cnt[0]*vec[0].bunshi;
            rep(i,10000) {
                x += vec[0].add;
                now -= vec[0].bunshi;
                ll now_ans = now;
                ll nx = x;
                if (now < 0) break;
                for (int j = 1; j <= 2; j++) {
                    cnt[j] = nx/vec[j].add;
                    now_ans += vec[j].bunshi * cnt[j];
                    nx = nx%vec[j].add;
                }
                chmin(ans, now_ans);
            }
        }


        cout << ans << endl;
    }
    return 0;
}