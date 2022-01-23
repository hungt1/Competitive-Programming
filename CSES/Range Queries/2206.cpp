/**
 *    author:    hungt1
 *    created:   23-01-2022   18:10:11
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
    vector<int> mn;
    int n;

    SegmentTree(int n = 0) : n(n){    
        mn.resize(4 * n + 1, 0);
    }

    SegmentTree(const vector<int> &a) : n(a.size()) {
        mn.resize(4 * n + 1, 0);
        function<void(int, int, int)> build = [&](int i, int l, int r){
            if (l == r){
                mn[i] = a[l - 1];
                return;
            }
            build(lc, l, m); build(rc, m + 1, r);
            mn[i] = min(mn[lc], mn[rc]);
        };
        build(1, 1, n);
    }

    void update(int i, int l, int r, int p, int val){
        if (l == r){
            mn[i] = val;
            return;
        }  
        if (p <= m) update(lc, l, m, p, val); 
        else update(rc, m + 1, r, p, val);
        mn[i] = min(mn[lc], mn[rc]);
    }
    
    int get(int i, int l, int r, int u, int v){
        if (v < l || r < u) return INF;
        if (u <= l && r <= v) return mn[i];
        return min(get(lc, l, m, u, v), get(rc, m + 1, r, u, v));
    }

    void update(int p, int val){
        update(1, 1, n, p, val);
    }

    int get(int l, int r){
        if (l < 1 || r > n || l > r) return INF;
        return get(1, 1, n, l, r);
    }
#undef m
#undef lc
#undef rc  
};

void solve(){
    int n, q; cin >> n >> q;
    vector<int> p(n);
    for (int &x : p) cin >> x;

    for (int i = 0; i < n; i++) p[i] -= i + 1;
    SegmentTree left(p);

    for (int i = 0; i < n; i++) p[i] += 2 * (i + 1);
    SegmentTree right(p);

    while (q--){
        int op; cin >> op;
        if (op == 1){
            int k, x; cin >> k >> x;
            left.update(k, x - k); right.update(k, x + k);
        }
        else {
            int k; cin >> k;
            cout << min(left.get(1, k) + k, right.get(k, n) - k) << '\n';
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