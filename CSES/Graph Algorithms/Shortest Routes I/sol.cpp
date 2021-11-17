/**
 *    author:    hungt1
 *    created:   17-11-2021   11:38:23
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
    priority_queue<pll, vector<pll>, greater<pll>> heap;
    vector<long> dis(n + 1, INF);
    dis[1] = 0; heap.push({0, 1});
    while (!heap.empty()){
        auto [cur, u] = heap.top();
        heap.pop();
        if (cur != dis[u]) continue;
        for (auto [v, c] : a[u]){
            if (dis[v] > cur + c){
                dis[v] = cur + c;
                heap.push({dis[v], v});
            }
        }
    }
    for (int i = 1; i <= n; i++){
        cout << dis[i] << " \n"[i == n];
    }
    return 0;
}