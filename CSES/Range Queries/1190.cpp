/**
 *    author:    hungt1
 *    created:   23-01-2022   18:24:36
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
    struct Node {
        long lt, rt, sum, mx;
        Node(int v = 0) : lt(v), rt(v), sum(v), mx(v) {}
    };
    
    vector<Node> itv;
    int n;

    SegmentTree(int n = 0) : n(n){    
        itv.resize(4 * n + 1, 0);
    }

    SegmentTree(const vector<int> &a) : n(a.size()) {
        itv.resize(4 * n + 1, 0);
        function<void(int, int, int)> build = [&](int i, int l, int r){
            if (l == r){
                itv[i] = a[l - 1];
                return;
            }
            build(lc, l, m); build(rc, m + 1, r);
            itv[i] = mer(itv[lc], itv[rc]);
        };
        build(1, 1, n);
    }

    Node mer(const Node& cur, const Node& other){
        Node ans;
        ans.lt = max(cur.lt, cur.sum + other.lt);
        ans.rt = max(other.rt, other.sum + cur.rt);
        ans.mx = max({cur.mx, other.mx, cur.rt + other.lt});
        ans.sum = cur.sum + other.sum;
        return ans;
    }

    void update(int i, int l, int r, int p, int val){
        if (l == r){
            itv[i] = val;
            return;
        }  
        if (p <= m) update(lc, l, m, p, val); 
        else update(rc, m + 1, r, p, val);
        itv[i] = mer(itv[lc], itv[rc]);
    }

    void update(int p, int val){
        update(1, 1, n, p, val);
    }

    long get(){
        return itv[1].mx; 
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
        int k, x; cin >> k >> x;
        tree.update(k, x);
        cout << max((long)0, tree.get()) << '\n';
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