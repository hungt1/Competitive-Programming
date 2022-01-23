/**
 *    author:    hungt1
 *    created:   23-01-2022   19:51:11
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
const int B = 450;
int x[N], cnt[N];

struct Query {
    int l, r, idx;
};

void solve(){
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> x[i];
    
    vector<int> val(x + 1, x + 1 + n);
    compress(val);
    for (int i = 1; i <= n; i++){
        x[i] = lower_bound(all(val), x[i]) - val.begin();
    }

    vector<Query> queries;
    for (int i = 0; i < q; i++){
        int l, r; cin >> l >> r;
        queries.push_back({l, r, i});
    }
    sort(all(queries), [](const Query& cur, const Query& other){
        if (cur.l / B != other.l / B){
            return (cur.l / B < other.l / B);
        }
        return cur.r < other.r;
    });
    int cur = 0, ptrL = 1, ptrR = 0;
    vector<int> ans(q);
    for (auto [l, r, i] : queries){
        while (ptrR < r){
            if (++cnt[x[++ptrR]] == 1) cur++;
        }
        while (ptrL > l){
            if (++cnt[x[--ptrL]] == 1) cur++;
        }
        while  (ptrR > r){
            if (--cnt[x[ptrR--]] == 0) cur--;
        }
        while (ptrL < l){
            if (--cnt[x[ptrL++]] == 0) cur--;
        }
        ans[i] = cur;
    }
    for (int i = 0; i < q; i++) cout << ans[i] << '\n';
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