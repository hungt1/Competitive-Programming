/**
 *    author:    hungt1
 *    created:   10-12-2021   16:23:30
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
    for (int i = 0; i < m; i++){
        int u, v, w; cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    vector<int> par(n + 1, 0);
    auto bellman = [&](int st) -> int{
        vector<long> dist(n + 1, INF);
        dist[st] = 0;
        for (int i = 0; i < n - 1; i++){
            for (auto [u, v, w] : edges){
                if (dist[v] > dist[u] + w){
                    dist[v] = dist[u] + w;
                    par[v] = u;
                }
            }
        }
        for (auto [u, v, w] : edges){
            if (dist[v] > dist[u] + w){
                par[v] = u;
                return v;                
            }
        }
        return -1;
    };
    int x = bellman(1);
    if (x == -1){
        cout << "NO\n";
    }
    else {
        for (int i = 0; i < n; i++) x = par[x];
        vector<int> ver = {x};
        for (x = par[x]; x != ver[0]; x = par[x]){
            ver.push_back(x);
        }
        ver.push_back(x); reverse(all(ver));
        cout << "YES\n";
        for (int u : ver) cout << u << ' '; cout << '\n';
    }
    return 0;
}