/**
 *    author:    hungt1
 *    created:   10-12-2021   15:47:48
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
    int n, m; cin >> n >> m;
    vector<vector<pii>> a(n + 1, vector<pii> ());
    for (int i = 0; i < m; i++){
        int u, v, c; cin >> u >> v >> c;
        a[u].push_back({v, c});
    }
    auto dijkstra = [&](int st, int ed) -> long{
        struct pack {
            int u, k;
            long d;
            bool operator < (const pack& other) const {
                return d > other.d;
            }
        };
        priority_queue<pack> heap;
        vector<vector<long>> dist(2, vector<long> (n + 1, INF));
        dist[0][st] = 0; heap.push({st, 0, 0});
        while (!heap.empty()){
            auto [u, k, du] = heap.top();
            heap.pop();
            if (du != dist[k][u]) continue;
            for (auto [v, c] : a[u]){
                if (dist[k][v] > dist[k][u] + c){
                    dist[k][v] = dist[k][u] + c;
                    heap.push({v, k, dist[k][v]});
                }
                if (k == 0 && dist[k + 1][v] > dist[k][u] + c / 2){
                    dist[k + 1][v] = dist[k][u] + c / 2;
                    heap.push({v, k + 1, dist[k + 1][v]});
                }
            }
        }
        return min(dist[0][ed], dist[1][ed]);
    };
    cout << dijkstra(1, n) << '\n';
    return 0;
}