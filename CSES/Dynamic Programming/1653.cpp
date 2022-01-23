/**
 *    author:    hungt1
 *    created:   09-11-2021   19:59:48
**/
#include <bits/stdc++.h>
using namespace std;

#define long long long
#define db double
#define pii pair <int, int>
#define pll pair <long, long>
#define all(c) c.begin(), c.end()
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

template <class T> inline void chmin(T &a, const T& val) { if (a > val) a = val; }
template <class T> inline void chmax(T &a, const T& val) { if (a < val) a = val; }
template <class T> long sqr(T a) { return 1ll * a * a; }
template <class T> void compress(T &a){
    sort(all(a)); a.resize(unique(all(a)) - a.begin());
}

const db pi = acos(-1.00);
const db eps = 1e-6;
const int INF = 2e9;
const int MOD = 1e9 + 7;
const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

int main()
{
    fastio;
    int n, x; cin >> n >> x;
    vector<int> w(n);
    for (int &val : w) cin >> val;
    vector<int> dp(1 << n, INF);
    vector<long> mn(1 << n, 1ll * INF * 10000);
    dp[0] = 1; mn[0] = 0;
    for (int mask = 0; mask < (1 << n); mask++){
        for (int i = 0; i < n; i++){
            if (mask >> i & 1) continue;
            int nxt = mask ^ (1 << i);
            if (mn[mask] + w[i] <= x){
                if (dp[mask] < dp[nxt] || (dp[mask] == dp[nxt] && mn[nxt] > mn[mask] + w[i])){
                    dp[nxt] = dp[mask];
                    mn[nxt] = mn[mask] + w[i];
                }
            }
            else {
                if (dp[mask] + 1 < dp[nxt] || (dp[mask] + 1 == dp[nxt] && mn[nxt] > w[i])){
                    dp[nxt] = dp[mask] + 1;
                    mn[nxt] = w[i];
                }
            }
        }
    }
    cout << dp[(1 << n) - 1];
    return 0;
}