/**
 *    author:    hungt1
 *    created:   17-11-2021   10:21:54
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
        a[v].push_back(u);
    }
    
    vector<int> visited(n + 1, 0), par(n + 1, -1);
    function<void(int, int)> dfs = [&](int p, int u){
        visited[u] = 1;
        for (int v : a[u]){
            if (v == p || visited[v] == 2) continue;
            if (visited[v] == 1){
                vector<int> ans;
                for (int cur = u; cur != v; cur = par[cur]){
                    ans.push_back(cur);
                }
                ans.push_back(v); reverse(all(ans));
                ans.push_back(v);
                cout << ans.size() << '\n';
                for (int x : ans) cout << x << ' ';
                exit(0);
            }
            par[v] = u; dfs(u, v);
        }
        visited[u] = 2;
    };

    for (int u = 1; u <= n; u++){
        if (!visited[u]) dfs(-1, u);
    }

    cout << "IMPOSSIBLE";
    return 0;
}