/**
 *    author:    hungt1
 *    created:   23-01-2022   16:53:14
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

struct SegmentTree {
#define m ((l + r) >> 1)
#define lc (i << 1)
#define rc (i << 1 | 1)
    vector<pii> mx;
    int n;

    SegmentTree(int n = 0) : n(n){    
        mx.resize(4 * n + 1, {0, 0});
    }

    SegmentTree(const vector<int> &a) : n(a.size()) {
        mx.resize(4 * n + 1, {0, 0});
        function<void(int, int, int)> build = [&](int i, int l, int r){
            if (l == r){
                mx[i] = {a[l - 1], -l};
                return;
            }
            build(lc, l, m); build(rc, m + 1, r);
            mx[i] = max(mx[lc], mx[rc]);
        };
        build(1, 1, n);
    }

    void update(int i, int l, int r, int p, int val){
        if (l == r){
            mx[i].first += val;
            return;
        }  
        if (p <= m) update(lc, l, m, p, val); 
        else update(rc, m + 1, r, p, val);
        mx[i] = max(mx[lc], mx[rc]);
    }
    
    pii get(int i, int l, int r, int u, int v){
        if (v < l || r < u) return {-INF, -INF};
        if (u <= l && r <= v) return mx[i];
        return max(get(lc, l, m, u, v), get(rc, m + 1, r, u, v));
    }

    int search(int i, int l, int r, int val){
        if (l > r || mx[i].first < val) return INF;
        if (l == r) return -mx[i].second;
        if (mx[lc].first >= val) return search(lc, l, m, val);
        else return search(rc, m + 1, r, val);
    }

    void update(int p, int val){
        update(1, 1, n, p, val);
    }

    int get(int val){
        int ans = search(1, 1, n, val);
        return (ans == INF ? 0 : ans);
    }
#undef m
#undef lc
#undef rc  
};

void solve(){
    int n, m; cin >> n >> m;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    SegmentTree tree(a);
    for (int i = 0; i < m; i++){
        int x; cin >> x;
        int pos = tree.get(x);
        cout << pos << " \n"[i == m - 1];
        if (pos != 0) tree.update(pos, -x);
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