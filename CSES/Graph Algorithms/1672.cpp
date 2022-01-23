/**
 *    author:    hungt1
 *    created:   17-11-2021   11:46:58
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
const long INF = 1e15;
const int MOD = 1e9 + 7;
const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

int main()
{
    fastio;
    int n, m, q; cin >> n >> m >> q;
    vector<vector<long>> dis(n + 1, vector<long> (n + 1, INF));
    for (int i = 1; i <= n; i++) dis[i][i] = 0;    
    for (int i = 0; i < m; i++){
        int u, v; long c; cin >> u >> v >> c;
        chmin(dis[u][v], c);
        chmin(dis[v][u], c);
    }
    for (int k = 1; k <= n; k++){
        for (int u = 1; u <= n; u++){
            for (int v = 1; v <= n; v++){
                chmin(dis[u][v], dis[u][k] + dis[k][v]);
            }
        }
    }
    while (q--){
        int u, v; cin >> u >> v;
        cout << (dis[u][v] == INF ? -1 : dis[u][v]) << '\n';
    }
    return 0;
}