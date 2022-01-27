/**
 *    author:    hungt1
 *    created:   26-01-2022   22:29:46
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
    for (int i = 2; i <= n; i++){
        cin >> par[i][0];
    }

    for (int i = 1; i <= 20; i++){
        for (int u = 1; u <= n; u++){
            par[u][i] = par[par[u][i - 1]][i - 1];
        }
    }
    auto query = [&](int u, int k) -> int {
        for (int i = 20; i >= 0; i--){
            if (k >> i & 1) u = par[u][i];
        }
        return (u == 0 ? -1 : u);
    };

    while (q--){
        int u, k; cin >> u >> k;
        cout << query(u, k) << '\n';
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