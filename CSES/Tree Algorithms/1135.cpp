/**
 *    author:    hungt1
 *    created:   26-01-2022   22:51:48
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

const int N = 2e5 + 1;
int par[N][21];

void solve(){
    int n, q; cin >> n >> q;
    vector<vector<int>> a(n + 1, vector<int> ());
    for (int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        a[u].push_back(v); a[v].push_back(u);
    }

    vector<int> h(n + 1, 0);
    function<void(int, int)> dfs = [&](int p, int u){
        for (int v : a[u]){
            if (v == p) continue;
            h[v] = h[u] + 1;
            par[v][0] = u;
            dfs(u, v);
        }
    };

    dfs(0, 1);
    
    for (int i = 1; i <= 20; i++){
        for (int u = 1; u <= n; u++){
            par[u][i] = par[par[u][i - 1]][i - 1];
        }
    }

    auto query = [&](int u, int v) -> int {
        if (h[u] < h[v]) swap(u, v);
        for (int k = 20; k >= 0; k--){
            if (h[u] - (1 << k) >= h[v]){
                u = par[u][k];
            }
        }    
        if (u == v) return u;
        for (int k = 20; k >= 0; k--){
            if (par[u][k] != par[v][k]){
                u = par[u][k];
                v = par[v][k];
            }
        }
        return par[u][0];
    };

    while (q--){
        int u, v; cin >> u >> v;
        int p = query(u, v);
        cout << h[u] + h[v] - 2 * h[p] << '\n';
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