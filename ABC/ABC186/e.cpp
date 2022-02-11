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

struct LDE{
    ll a,b,c,x0,y0;
    ll m=0;
    bool check=true;//解が存在するか

    //初期化
    LDE(ll a_,ll b_,ll c_): a(a_),b(b_),c(c_){
        //llが128bit整数の可能性があるのでlong longにキャスト
        ll g=__gcd(static_cast<long long>(a),static_cast<long long>(b));
        if(c%g!=0){
            check=false;
        }else{
            //ax+by=gの特殊解を求める
            extgcd(a,b,x0,y0);
            //ax+by=cの特殊解を求める(オーバフローに注意！)
            x0*=c/g;y0*=c/g;
            //一般解を求めるために割る
            a/=g;b/=g;
        }
    }

    //拡張ユークリッドの互除法
    //返り値:aとbの最大公約数
    ll extgcd(ll a,ll b,ll &x,ll &y){
        if(b==0){
            x=1;
            y=0;
            return a;
        }
        ll d=extgcd(b,a%b,y,x);
        y-=a/b*x;
        return d;
    }

    //パラメータmの更新(書き換え)
    void m_update(ll m_){
        x0+=(m_-m)*b;
        y0-=(m_-m)*a;
        m=m_;
    }
};

int main() {
    int t;
    cin >> t;
    rep(i,t) {
        ll n, s, k;
        cin >> n >> s >> k;
        ll t = __gcd(k, n);
        if (s%t != 0) {
            cout << -1 << endl;
            continue;
        } 
        LDE abc{-k,n,s};
        ll x = abc.x0;
        ll y = abc.y0;
        n /= t;
        if (x >= 0) {
            ll ans = x;
            while (ans >= 0) {
                ans -= n;
            }
            ans += n;
            cout << ans << endl;
            continue;
        } else {
            ll ans = x;
            while (ans < 0) {
                ans += n;
            }
            cout << ans << endl;
            continue;
        }
    }
    return 0;
}