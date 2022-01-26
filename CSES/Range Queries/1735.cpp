/**
 *    author:    hungt1
 *    created:   26-01-2022   17:18:19
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

struct LazySegmentTree {
#define m ((l + r) >> 1)
#define lc (i << 1)
#define rc (i << 1 | 1)
    vector<long> sum, lazy_inc, lazy_set;
    int n;

    LazySegmentTree(int n = 0) : n(n){
        sum.resize(4 * n + 1, 0);
        lazy_inc.resize(4 * n + 1, 0);
    }
    LazySegmentTree(const vector<int> &a) : n(a.size()) {
        sum.resize(4 * n + 1, 0); 
        lazy_inc.resize(4 * n + 1, 0); lazy_set.resize(4 * n + 1, 0);
        function<void(int, int, int)> build = [&](int i, int l, int r){
            if (l == r){
                sum[i] = a[l - 1];
                return;
            }
            build(lc, l, m); build(rc, m + 1, r);
            sum[i] = sum[lc] + sum[rc];
        };
        build(1, 1, n);
    }

    void push_inc(int i, int l, int r){
        if (lazy_inc[i] == 0) return;
        sum[i] += lazy_inc[i] * (r - l + 1);
        if (l != r){
            lazy_inc[lc] += lazy_inc[i];
            lazy_inc[rc] += lazy_inc[i];
        }  
        lazy_inc[i] = 0;
    }
    void update_inc(int i, int l, int r, int u, int v, int val){
        push_set(i, l, r); push_inc(i, l, r);
        if (v < l || r < u) return;
        if (u <= l && r <= v){
            lazy_inc[i] += val;
            push_inc(i, l, r);
            return;
        }  
        update_inc(lc, l, m, u, v, val); update_inc(rc, m + 1, r, u, v, val);
        sum[i] = sum[lc] + sum[rc];
    }

    void push_set(int i, int l, int r){
        if (lazy_set[i] == 0) return;
        sum[i] = lazy_set[i] * (r - l + 1);
        if (l != r){
            lazy_set[lc] = lazy_set[i]; lazy_inc[lc] = 0;
            lazy_set[rc] = lazy_set[i]; lazy_inc[rc] = 0;
        }  
        lazy_set[i] = 0;
    }
    void update_set(int i, int l, int r, int u, int v, int val){
        push_set(i, l, r); push_inc(i, l, r);
        if (v < l || r < u) return;
        if (u <= l && r <= v){
            lazy_set[i] = val; lazy_inc[i] = 0;
            push_set(i, l, r);
            return;
        }  
        update_set(lc, l, m, u, v, val); update_set(rc, m + 1, r, u, v, val);
        sum[i] = sum[lc] + sum[rc];
    }

    long get(int i, int l, int r, int u, int v){
        push_set(i, l, r); push_inc(i, l, r);
        if (v < l || r < u) return 0;
        if (u <= l && r <= v) return sum[i];
        return get(lc, l, m, u, v) + get(rc, m + 1, r, u, v);
    }

    void update_inc(int l, int r, int val){
        update_inc(1, 1, n, l, r, val);
    }
    void update_set(int l, int r, int val){
        update_set(1, 1, n, l, r, val);
    }
    long get(int l, int r){
        return get(1, 1, n, l, r);
    }
#undef m
#undef lc
#undef rc  
};

void solve(){
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    LazySegmentTree tree(a);
    while (q--){
        int op, l, r; cin >> op >> l >> r;
        if (op == 1 || op == 2){
            int x; cin >> x;
            if (op == 1) tree.update_inc(l, r, x);
            else tree.update_set(l, r, x);
        }
        else {
            cout << tree.get(l, r) << '\n';
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