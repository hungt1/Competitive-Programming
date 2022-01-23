/**
 *    author:    hungt1
 *    created:   23-01-2022   17:25:29
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
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

struct FenwickTree {
    int n;
    vector<int> bit;

    FenwickTree(int n = 0) : n(n) {
        bit.resize(n + 1, 0);
    }
    void update(int p, int val){
        for (; p <= n; p += p&-p){
            bit[p] += val;
        }
    }
    int get(int p){
        int ans = 0;
        for (; p > 0; p -= p&-p){
            ans += bit[p];
        }
        return ans;
    }
};

struct Query{
    char op;
    int x, y;
};

void solve(){
    int n, q; cin >> n >> q;
    vector<int> p(n);
    for (int &x : p) cin >> x;

    vector<int> val(all(p));
    
    vector<Query> queries;
    while (q--){
        char op; cin >> op;
        int x, y; cin >> x >> y;
        if (op == '?'){
            val.push_back(x - 1); 
            val.push_back(y);
        }
        else {
            val.push_back(y);
        }
        queries.push_back({op, x, y});
    }
    compress(val);

    FenwickTree fen(val.size());
    
    auto index = [&](int x){
        return upper_bound(all(val), x) - val.begin();
    };

    for (int x : p) fen.update(index(x), 1);
    for (auto [op, x, y] : queries){
        if (op == '?'){
            cout << fen.get(index(y)) - fen.get(index(x - 1)) << '\n';
        }
        else {
            fen.update(index(p[x - 1]), -1);
            p[x - 1] = y;
            fen.update(index(p[x - 1]), 1);
        }   
    }
}

int main()
{
    fastio;
    int T = 1; //cin >> T;
    while (T--){
        solve();
    }
    return 0;
}