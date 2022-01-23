/**
 *    author:    hungt1
 *    created:   23-01-2022   17:46:21
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
const long INF = 1e15;
const int MOD = 1e9 + 7;
const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

struct LazySegmentTree {
#define m ((l + r) >> 1)
#define lc (i << 1)
#define rc (i << 1 | 1)
    vector<long> mx, lazy;
    int n;

    LazySegmentTree(int n = 0) : n(n){
        mx.resize(4 * n + 1, 0);
        lazy.resize(4 * n + 1, 0);
    }

    LazySegmentTree(const vector<long> &a) : n(a.size()) {
        mx.resize(4 * n + 1, 0); lazy.resize(4 * n + 1, 0);
        function<void(int, int, int)> build = [&](int i, int l, int r){
            if (l == r){
                mx[i] = a[l - 1];
                return;
            }
            build(lc, l, m); build(rc, m + 1, r);
            mx[i] = max(mx[lc], mx[rc]);
        };
        build(1, 1, n);
    }

    void push(int i, int l, int r){
        if (lazy[i] == 0) return;
        mx[i] += lazy[i];
        if (l != r){
            lazy[lc] += lazy[i];
            lazy[rc] += lazy[i];
        }  
        lazy[i] = 0;
    }

    void update(int i, int l, int r, int u, int v, int val){
        push(i, l, r);
        if (v < l || r < u) return;
        if (u <= l && r <= v){
            lazy[i] += val;
            push(i, l, r);
            return;
        }  
        update(lc, l, m, u, v, val); update(rc, m + 1, r, u, v, val);
        mx[i] = max(mx[lc], mx[rc]);
    }

    long get(int i, int l, int r, int u, int v){
        push(i, l, r);
        if (v < l || r < u) return -INF;
        if (u <= l && r <= v) return mx[i];
        return max(get(lc, l, m, u, v), get(rc, m + 1, r, u, v));
    }

    void update(int l, int r, int val){
        update(1, 1, n, l, r, val);
    }

    long get(int l, int r){
        if (r == 0 || l > r) return 0;
        return get(1, 1, n, l, r);
    }
#undef m
#undef lc
#undef rc  
};

void solve(){
    int n, q; cin >> n >> q;
    vector<long> a(n), psum(n, 0);
    for (int i = 0; i < n; i++){
        cin >> a[i];
        psum[i] = a[i];
        if (i > 0) psum[i] += psum[i - 1];
    }

    LazySegmentTree tree(psum);
    while (q--){
        int op, x, y; cin >> op >> x >> y;
        if (op == 1){
            int delta = y - a[x - 1];
            a[x - 1] = y;
            tree.update(x, n, delta);
        }
        else {
            long pre = tree.get(x - 1, x - 1);
            long ans = tree.get(x, y) - pre;
            cout <<  max((long)0, ans) << '\n';
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