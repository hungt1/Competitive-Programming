/**
 *    author:    hungt1
 *    created:   23-01-2022   19:42:48
**/
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using pll = pair<int64_t, int64_t>;
using ld = long double;

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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve(){
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) a[i] = i + 1;
    ordered_set<int> s(all(a));
    int cur = 0;
    while (s.size()){
        cur = (cur + k) % s.size();
        auto it = s.find_by_order(cur);
        cout << *it << ' ';
        s.erase(it);
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