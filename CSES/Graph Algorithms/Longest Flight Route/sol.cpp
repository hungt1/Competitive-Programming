/**
 *    author:    hungt1
 *    created:   13-12-2021   10:43:15
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
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n + 1, vector<int> ());
    for (int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        a[u].push_back(v); 
    }
    vector<int> nxt(n + 1, -1), dp(n + 1, -INF);
    vector<bool> visited(n + 1, false);
    function<void(int)> dfs = [&](int u){
        visited[u] = true;
        if (u == n) dp[u] = 1;
        for (int v : a[u]){
            if (!visited[v]) dfs(v);
            if (dp[u] < dp[v] + 1){
                dp[u] = dp[v] + 1;
                nxt[u] = v;
            }
        }
    };
    dfs(1);
    if (dp[1] <= 0){
        cout << "IMPOSSIBLE\n";
    }
    else {
        vector<int> ver;
        for (int u = 1; u != -1; u = nxt[u]){
            ver.push_back(u);
        }
        cout << ver.size() << '\n';
        for (int i = 0; i < ver.size(); i++){
            cout << ver[i] << " \n"[i == ver.size() - 1];
        }
    }
    return 0;
}