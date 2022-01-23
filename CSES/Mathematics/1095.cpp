/**
 *    author:    hungt1
 *    created:   23-01-2022   21:09:26
**/
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using pll = pair<int64_t, int64_t>;
using ld = long double;

#define long int64_t
#define all(c) c.begin(), c.end()
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)

template <class T> inline void chmin(T &a, const T& val) { if (a > val) a = val; }
template <class T> inline void chmax(T &a, const T& val) { if (a < val) a = val; }
template <class T> long sqr(T a) { return 1ll * a * a; }
template <class T> void compress(T &a) { sort(all(a)); a.resize(unique(all(a)) - a.begin()); }
template <class T> T power(T x, long n){
    T res = 1;
    for (; n; x *= x, n >>= 1){
        if (n & 1) res *= x;
    }
    return res;
}

const double pi = acos(-1.00);
const double eps = 1e-6;
const int INF = 2e9;
const int MOD = 1e9 + 7;
const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

template <int mod> struct Modular {
    int x;
    Modular(long x = 0) {
        this->x = (x % mod);
        if (this->x < 0) this->x += mod;
    }
    Modular inv() const {
        assert(x != 0);
        return power(*this, mod - 2);
    }
    Modular& operator += (const Modular& other){
        if ((x += other.x) >= mod) x -= mod;
        return *this;
    }
    Modular& operator -= (const Modular& other){
        if ((x -= other.x) < 0) x += mod;
        return *this;
    }
    Modular& operator *= (const Modular& other){
        x = 1ll * x * other.x % mod;
        return *this;
    }
    Modular& operator /= (const Modular& other){ 
        return *this *= other.inv();
    }
    friend Modular operator + (const Modular& lhs, const Modular& rhs) { return Modular(lhs) += rhs; }
    friend Modular operator - (const Modular& lhs, const Modular& rhs) { return Modular(lhs) -= rhs; }
    friend Modular operator * (const Modular& lhs, const Modular& rhs) { return Modular(lhs) *= rhs; }
    friend Modular operator / (const Modular& lhs, const Modular& rhs) { return Modular(lhs) /= rhs; }
    Modular& operator ++ () { return *this += 1; }
    Modular& operator -- () { return *this -= 1; }
    Modular operator ++ (int) { Modular res(*this); *this += 1; return res; }
    Modular operator -- (int) { Modular res(*this); *this -= 1; return res; } 
    Modular operator - () const { return Modular(-x); }
    explicit operator int () const { return x; }
    friend ostream& operator << (ostream& os, const Modular& cur){ return os << cur.x; }
    friend istream& operator >> (istream& is, Modular& cur){ return is >> cur.x; }
    friend string to_string(const Modular& cur){ return to_string(cur.x); }
};
using mint = Modular<MOD>;

void solve(){
    mint a; int b; cin >> a >> b;
    cout << power(a, b) << '\n';
}

int main()
{
    fastio;
    int T = 1; cin >> T;
    while (T--){
        solve();
    }
    return 0;
}