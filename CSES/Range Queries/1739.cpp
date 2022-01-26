/**
 *    author:    hungt1
 *    created:   26-01-2022   16:52:39
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

struct FenwickTree2D{
    int n;
    vector<vector<int>> bit;
    
    FenwickTree2D(int n = 0) : n(n){
        bit.resize(n + 1, vector<int> (n + 1, 0));
    }
    void update(int u, int v, int val){
        for (int x = u; x <= n; x += x&-x){
            for (int y = v; y <= n; y += y&-y){
                bit[x][y] += val;
            }
        }
    }
    int get(int u, int v){
        int ans = 0;
        for (int x = u; x > 0; x -= x&-x){
            for (int y = v; y > 0; y -= y&-y){
                ans += bit[x][y];
            }
        }
        return ans;
    }
    int get(int u, int v, int x, int y){
        return get(x, y) - get(u - 1, y) - get(x, v - 1) + get(u - 1, v - 1);
    }   
};

void solve(){
    int n, q; cin >> n >> q;
    vector<vector<int>> a(n + 1, vector<int> (n + 1));
    FenwickTree2D tree(n);
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            char c; cin >> c;
            if (c == '*') a[i][j] = 1;
            tree.update(i, j, a[i][j]);
        }
    }

    while (q--){
        int op; cin >> op;
        if (op == 1){
            int u, v; cin >> u >> v;
            int new_val = 1 - a[u][v];
            tree.update(u, v, new_val - a[u][v]);
            a[u][v] = new_val;
        }
        else {
            int u, v, x, y; cin >> u >> v >> x >> y;
            cout << tree.get(u, v, x, y) << '\n';
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