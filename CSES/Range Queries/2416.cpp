/**
 *    author:    hungt1
 *    created:   26-01-2022   15:26:48
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

const int N = 2e5 + 2;
int a[N], nxt[21][N];
long psum[N], sum[21][N];

void solve(){
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        psum[i] = psum[i - 1] + a[i];
    }

    stack<int> st;
    for (int i = n; i >= 1; i--){
        while (!st.empty() && a[st.top()] <= a[i]) st.pop();
        nxt[0][i] = (st.empty() ? n + 1 : st.top());
        sum[0][i] = 1ll * a[i] * (nxt[0][i] - i) - psum[nxt[0][i] - 1] + psum[i - 1];
        st.push(i);
    }

    for (int i = 1; i < 21; i++){
        for (int j = 1; j <= n; j++){
            nxt[i][j] = nxt[i - 1][nxt[i - 1][j]];
            sum[i][j] = sum[i - 1][j] + sum[i - 1][nxt[i - 1][j]];
        }
    }

    auto query = [&](int l, int r) -> long {
        long ans = 0;
        for (int i = 20; i >= 0; i--){
            if (nxt[i][l] != 0 && nxt[i][l] - 1 <= r){
                ans += sum[i][l];
                l = nxt[i][l];
            }
        }
        int len = r - l + 1;
        if (len != 0) ans += 1ll * a[l] * len - (psum[r] - psum[l - 1]);
        return ans;
    };

    while (q--){
        int l, r; cin >> l >> r;
        cout << query(l, r) << '\n';
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