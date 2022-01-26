/**
 *    author:    hungt1
 *    created:   26-01-2022   19:39:31
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
    struct Node{
        long start, diff, sum;
        Node(long st = 0, long d = 0, long s = 0){
            start = st; diff = d; sum = s;   
        }
    };

    vector<Node> st;
    int n;

    LazySegmentTree(int n = 0) : n(n){
        st.resize(4 * n + 1);
    }

    LazySegmentTree(const vector<int> &a) : n(a.size()) {
        st.resize(4 * n + 1);
        function<void(int, int, int)> build = [&](int i, int l, int r){
            if (l == r){
                st[i] = {0, 0, a[l - 1]};
                return;
            }
            build(lc, l, m); build(rc, m + 1, r);
            st[i].sum = st[lc].sum + st[rc].sum;
        };
        build(1, 1, n);
    }

    void push(int i, int l, int r){
        if (st[i].diff == 0) return;
        int len = r - l + 1;
        st[i].sum += st[i].start * len + st[i].diff * (len - 1) * len / 2;
        if (l != r){
            st[lc].start += st[i].start;
            st[rc].start += st[i].start + (m - l + 1) * st[i].diff; 
            st[lc].diff += st[i].diff;
            st[rc].diff += st[i].diff;
        }  
        st[i].start = st[i].diff = 0;
    }

    void update(int i, int l, int r, int u, int v, int s = 1){
        push(i, l, r);
        if (v < l || r < u) return;
        if (u <= l && r <= v){
            st[i].start += s + l - u; st[i].diff += 1;
            push(i, l, r);
            return;
        }  
        update(lc, l, m, u, v, s); update(rc, m + 1, r, u, v, s);
        st[i].sum = st[lc].sum + st[rc].sum;
    }

    long get(int i, int l, int r, int u, int v){
        push(i, l, r);
        if (v < l || r < u) return 0;
        if (u <= l && r <= v) return st[i].sum;
        return get(lc, l, m, u, v) + get(rc, m + 1, r, u, v);
    }

    void update(int l, int r){
        update(1, 1, n, l, r);
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
        if (op == 1) tree.update(l, r);
        else cout << tree.get(l, r) << '\n';
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