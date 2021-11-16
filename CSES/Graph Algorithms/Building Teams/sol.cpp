/**
 *    author:    hungt1
 *    created:   16-11-2021   11:13:14
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
    
    vector<int> color(n + 1, 0);
    function<void(int, int)> dfs = [&](int u, int cur){
        color[u] = cur;
        for (int v : a[u]){
            if (color[v]){
                if (color[v] == cur){
                    cout << "IMPOSSIBLE";
                    exit(0);
                }
            }
            else {
                dfs(v, 3 - cur);
            }
        }
    };
    for (int i = 1; i <= n; i++){
        if (color[i] == 0) dfs(i, 1);
    }
    for (int i = 1; i <= n; i++){
        cout << color[i] << " \n"[i == n];
    }
    return 0;
}