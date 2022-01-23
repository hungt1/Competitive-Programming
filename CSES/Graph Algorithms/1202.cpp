/**
 *    author:    hungt1
 *    created:   13-12-2021   11:13:57
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
    vector<vector<pii>> a(n + 1, vector<pii> ());
    for (int i = 0; i < m; i++){
        int u, v, c; cin >> u >> v >> c;
        a[u].push_back({v, c});        
    }    
    auto dijkstra = [&](int st, int ed){
        vector<long> dist(n + 1, 1ll * INF * INF);
        vector<int> mn(n + 1, INF), mx(n + 1, -INF), cnt(n + 1, 0);
        dist[st] = mn[st] = mx[st] = 0; 
        cnt[st] = 1;
        priority_queue<pll, vector<pll>, greater<pll>> heap;
        heap.push({0, st});
        while (!heap.empty()){
            auto [du, u] = heap.top();
            heap.pop();
            if (du != dist[u]) continue;
            for (auto [v, c] : a[u]){
                if (dist[v] > dist[u] + c){
                    dist[v] = dist[u] + c;
                    cnt[v] = cnt[u];
                    mn[v] = mn[u] + 1;
                    mx[v] = mx[u] + 1;
                    heap.push({dist[v], v});
                }
                else if (dist[v] == dist[u] + c){
                    (cnt[v] += cnt[u]) %= MOD;
                    chmin(mn[v], mn[u] + 1);
                    chmax(mx[v], mx[u] + 1);
                }
            }
        }
        cout << dist[ed] << ' ' << cnt[ed] << ' ' << mn[ed] << ' ' << mx[ed] << '\n';
    };
    dijkstra(1, n);
    return 0;
}