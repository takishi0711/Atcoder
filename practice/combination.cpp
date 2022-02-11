#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

// auto mod int
// https://youtu.be/L8grWxBlIZ4?t=9858
// https://youtu.be/ERZuLAxZffQ?t=4807 : optimize
// https://youtu.be/8uowVvQ_-Mo?t=1329 : division
//const int mod = 998244353;
const int mod = 1000000007;
struct mint {
  ll x; // typedef long long ll;
  mint(ll x=0):x((x%mod+mod)%mod){}
  mint operator-() const { return mint(-x);}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += mod-a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint a) {
    (x *= a.x) %= mod;
    return *this;
  }
  mint operator+(const mint a) const {
    mint res(*this);
    return res+=a;
  }
  mint operator-(const mint a) const {
    mint res(*this);
    return res-=a;
  }
  mint operator*(const mint a) const {
    mint res(*this);
    return res*=a;
  }
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }
 
  // for prime mod
  mint inv() const {
    return pow(mod-2);
  }
  mint& operator/=(const mint a) {
    return (*this) *= a.inv();
  }
  mint operator/(const mint a) const {
    mint res(*this);
    return res/=a;
  }
};
istream& operator>>(istream&i,mint&a){i>>a.x;return i;}
ostream& operator<<(ostream&o,const mint&a){o<<a.x;return o;}


// combination mod prime
// https://www.youtube.com/watch?v=8uowVvQ_-Mo&t=1619
struct combination {
  vector<mint> fact, ifact;
  combination(int n):fact(n+1),ifact(n+1) {
    //assert(n < mod);
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) fact[i] = fact[i-1]*i;
    ifact[n] = fact[n].inv();
    for (int i = n; i >= 1; --i) ifact[i-1] = ifact[i]*i;
  }
  mint operator()(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fact[n]*ifact[k]*ifact[n-k];
  }
  mint p(int n, int k) {
    return fact[n]*ifact[n-k];
  }
} comb(1000005);

mint choose (int n, int a) {
    mint x = 1, y = 1;
    rep(i,a) {
        x *= n-i;
        y *= i+1;
    }
    return x / y;
}

ll choose2(int n, int a) {
    ll res = 1;
    rep(i,a) {
        res *= n-i;
        res /= i+1;
    }
    return res;
}

mint f(int n, int k) {
  if (n < 0) return 0;
  // nPk = nCk * k!
  mint res = c(n,k);
  res *= c.fact[k];
  return res;
}

int main() {
  int x, y;
  cin >> x >> y;
  if ((x+y)%3) {
    cout << 0 << endl;
    return 0;
  }
  int n = (x+y)/3;
  x -= n; y -= n;
  if (x < 0 || y < 0) {
    cout << 0 << endl;
    return 0;
  }
  combination c(x+y);
  mint ans = c(x+y,x);
  cout << ans.x << endl;
  return 0;
}
