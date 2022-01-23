/**
 *    author:    hungt1
 *    created:   23-01-2022   17:17:55
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

struct FenwickTree {
    int n;
    vector<int> bit;

    FenwickTree(int n = 0) : n(n) {
        bit.resize(n + 1, 0);
    }

    void update(int p, int val){
        for (; p <= n; p += p&-p){
            bit[p] += val;
        }
    }

    int get(int p){
        int ans = 0;
        for (; p > 0; p -= p&-p){
            ans += bit[p];
        }
        return ans;
    }
};

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    FenwickTree fen(n);
    for (int i = 1; i <= n; i++) fen.update(i, 1);    

    for (int i = 0; i < n; i++){
        int x; cin >> x;
        int l = 1, r = n, pos = -1;
        while (l <= r){
            int m = (l + r) / 2;
            if (fen.get(m) >= x){
                pos = m;
                r = m - 1;
            }
            else l = m + 1;
        }
        fen.update(pos, -1);
        cout << a[pos - 1] << " \n"[i == n - 1];
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