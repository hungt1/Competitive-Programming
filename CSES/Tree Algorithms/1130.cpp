/**
 *    author:    hungt1
 *    created:   23-01-2022   20:29:07
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

void solve(){
    int n; cin >> n;
    vector<vector<int>> a(n + 1, vector<int> ());
    for (int i = 0; i < n - 1; i++){
        int u, v; cin >> u >> v;
        a[u].push_back(v); a[v].push_back(u);
    }

    vector<int> color(n + 1, 0);
    int cnt = 0;
    function<void(int, int)> dfs = [&](int p, int u){
        for (int v : a[u]){
            if (v == p) continue;
            dfs(u, v);
        }
        if (p != 0 && !color[u] && !color[p]){
            color[u] = color[p] = 1;
            cnt++;
        }
    };
    dfs(0, 1);
    cout << cnt << '\n';
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