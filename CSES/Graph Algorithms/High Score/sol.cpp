/**
 *    author:    hungt1
 *    created:   10-12-2021   15:05:10
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

struct pack {
    int u, v, w;
};

int main()
{
    fastio;
    int n, m; cin >> n >> m;
    vector<pack> edges;
    vector<long> dist(n + 1, -INF);
    auto bellman = [&](int st, int ed) -> long{
        dist[st] = 0;
        for (int i = 0; i < n - 1; i++){
            for (auto e : edges){
                if (dist[e.u] != -INF){
                    chmax(dist[e.v], dist[e.u] + e.w);
                }
            }
        }
        for (int i = 0; i < n - 1; i++){
            for (auto e : edges){
                if (dist[e.u] != -INF && dist[e.v] < dist[e.u] + e.w){
                    dist[e.v] = INF;
                    if (e.v == ed) return -1;
                }
            }
        }
        return dist[ed];
    };
    for (int i = 0; i < m; i++){
        int u, v, x; cin >> u >> v >> x;
        edges.push_back({u, v, x});
    }
    cout << bellman(1, n) << '\n';
    return 0;
}