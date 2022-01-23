/**
 *    author:    hungt1
 *    created:   23-01-2022   21:22:21
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

const int N = 1e6 + 1;
int ans[N];

void solve(){
    int x; cin >> x;
    cout << ans[x] << '\n';
}

int main()
{
    fastio;
    for (int i = N - 1; i > 0; i--){
        ans[i]++;
        for (int j = 2 * i; j < N; j += i){
            ans[j] += ans[i];
        }
    }
    int T = 1; cin >> T;
    while (T--){
        solve();
    }
    return 0;
}