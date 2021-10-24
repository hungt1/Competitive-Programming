/**
 *    author:    hungt1
 *    created:   07-08-2021   00:05:13
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

const db eps = 1e-6;
const int INF = 2e9;
const int MOD = 1e9 + 7;
const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};
 
int main()
{
    fastio;
    vector<vector<int>> C(101, vector<int> (101, 0));
    for (int i = 0; i <= 100; i++){
        for (int j = i; j <= 100; j++){
            if (i == 0 || i == j) C[i][i] = 1;
            else {
                C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
            }
        }
    }
    int T; cin >> T;
    while (T--){
        int n, k; cin >> n >> k;
        vector<vector<int>> graph(n + 1, vector<int> ());
        for (int i = 1; i < n; i++){
            int u, v; cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        if (k == 2){
            cout << 1ll * n * (n - 1) / 2 << '\n';
            continue;
        }
        vector<vector<int>> h(n + 1, vector<int> (n + 1, 0));
        function<void(int, int, int, int)> dfs = [&](int p, int u, int cur, int depth){
            h[cur][depth]++;
            for (int v : graph[u]){
                if (v == p) continue;
                dfs(u, v, cur, depth + 1);
            }
        };
        int ans = 0;
        for (int r = 1; r <= n; r++){
            for (int c : graph[r]){
                for (int i = 1; i <= n; i++) h[c][i] = 0;
                dfs(r, c, c, 1);
            }
            int m = graph.size(); 
            vector<vector<int>> dp(n + 1, vector<int> (k + 1, 0));
            for (int i = 1; i <= n; i++) dp[i][0] = 1;
            for (int c : graph[r]){
                for (int i = 1; i <= n; i++){
                    for (int j = k; j > 0; j--){
                        (dp[i][j] += 1ll * dp[i][j - 1] * h[c][i] % MOD) %= MOD;
                    }
                }
            }
            for (int i = 1; i <= n; i++) (ans += dp[i][k]) %= MOD;
        }
        cout << ans << '\n';
    }
    return 0;
}