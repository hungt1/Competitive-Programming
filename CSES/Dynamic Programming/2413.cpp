/**
 *    author:    hungt1
 *    created:   04-11-2021   10:26:59
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

const int N = 1e6;

int main()
{
    fastio;
    vector<vector<long>> dp(N + 1, vector<long> (2, 0));
    dp[1][0] = dp[1][1] = 1;
    for (int i = 1; i < N; i++){
        dp[i + 1][1] = (dp[i][1] * 2 + dp[i][0]) % MOD;
        dp[i + 1][0] = (dp[i][0] * 4 + dp[i][1]) % MOD;
    }
    int T; cin >> T;
    while (T--){
        int n; cin >> n;
        cout << (dp[n][0] + dp[n][1]) % MOD << '\n';
    }
    return 0;
}