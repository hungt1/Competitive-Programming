/**
 *    author:    hungt1
 *    created:   27-01-2022   09:38:30
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

struct PersistenSegmentTree{
#define m ((l + r) >> 1)
    struct Node {
        Node *lt, *rt;
        long sum;
        Node(Node* l = nullptr, Node* r = nullptr, long s = 0) : sum(s) {
            lt = l; rt = r;
        }
        Node(Node* lc, Node* rc){
            sum = lc->sum + rc->sum;
            lt = rt = nullptr;
        }
    };
    vector<Node*> ver;
    int cnt, n;

    PersistenSegmentTree(const vector<int> &a) : n(a.size()), cnt(1){
        function<void(Node*, int, int)> build = [&](Node* cur, int l, int r){
            if (l == r){
                cur->sum = a[l - 1];
                return;
            }
            cur->lt = new Node; cur->rt = new Node;
            build(cur->lt, l, m); build(cur->rt, m + 1, r);
            cur->sum = cur->lt->sum + cur->rt->sum;
        };
        Node* new_version = new Node;
        build(new_version, 1, n);
        ver.push_back(new_version);
    }

    void update(Node* prev, Node* cur, int l, int r, int p, int val){
        if (l == r){
            cur->sum = val;
            return;
        }
        Node *lc = prev->lt, *rc = prev->rt;
        if (p <= m){
            cur->rt = prev->rt; cur->lt = new Node;
            update(lc, cur->lt, l, m, p, val);
        }
        else {
            cur->lt = prev->lt; cur->rt = new Node;
            update(rc, cur->rt, m + 1, r, p, val);
        }
        cur->sum = cur->lt->sum + cur->rt->sum;
    }

    long get(Node* cur, int l, int r, int u, int v){
        if (v < l || r < u) return 0;
        if (u <= l && r <= v) return cur->sum;
        return get(cur->lt, l, m, u, v) + get(cur->rt, m + 1, r, u, v);

    }

    void update(int k, int p, int val){
        update(ver[k], ver[k], 1, n, p, val);
    }

    long get(int k, int l, int r){
        return get(ver[k], 1, n, l, r);
    }

    void clone(int k){
        Node* new_ver = new Node(ver[k]->lt, ver[k]->rt, ver[k]->sum);
        ver.push_back(new_ver); cnt++;
    }
#undef m
};

void solve(){
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    
    PersistenSegmentTree tree(a);
    while (q--){
        int op, k; cin >> op >> k; k--;
        if (op == 1){
            int a, x; cin >> a >> x;
            tree.update(k, a, x);
        }
        else if (op == 2){
            int l, r; cin >> l >> r; 
            cout << tree.get(k, l, r) << '\n';
        }
        else tree.clone(k);
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