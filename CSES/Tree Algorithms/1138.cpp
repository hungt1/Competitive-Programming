/**
 *    author:    hungt1
 *    created:   27-01-2022   13:24:27
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

struct FenwickTree {
    int n;
    vector<long> bit;

    FenwickTree(int n = 0) : n(n) {
        bit.resize(n + 1, 0);
    }
    void update(int p, int val){
        for (; p <= n; p += p&-p){
            bit[p] += val;
        }
    }
    long get(int p){
        long ans = 0;
        for (; p > 0; p -= p&-p){
            ans += bit[p];
        }
        return ans;
    }
    void update(int l, int r, int val){
        update(l, val); update(r + 1, -val);
    }
};

void solve(){
    int n, q; cin >> n >> q;
    vector<int> val(n + 1);
    for (int i = 1; i <= n; i++) cin >> val[i];
    vector<vector<int>> a(n + 1, vector<int> ());
    for (int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        a[u].push_back(v); a[v].push_back(u);
    }

    vector<int> st(n + 1, 0), ed(n + 1, 0);
    int cnt = 0;
    function<void(int, int)> dfs = [&](int p, int u){
        st[u] = ++cnt;
        for (int v : a[u]){
            if (v == p) continue;
            dfs(u, v);
        }
        ed[u] = cnt;
    };
    dfs(0, 1);

    FenwickTree fen(n);
    for (int u = 1; u <= n; u++){
        fen.update(st[u], ed[u], val[u]);
    }
    while (q--){
        int op; cin >> op;
        if (op == 1){
            int s, x; cin >> s >> x;
            fen.update(st[s], ed[s], x - val[s]);
            val[s] = x;
        }
        else {
            int s; cin >> s;
            cout << fen.get(st[s]) << '\n';
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