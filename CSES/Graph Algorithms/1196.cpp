// source: https://github.com/ncduy0303/cses-solutions/blob/master/src/1196.cpp

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
    int n, m, k; cin >> n >> m >> k;
    vector<vector<pii>> a(n + 1, vector<pii> ());
    vector<long> ans;
    vector<int> cnt(n + 1, 0);
    for (int i = 0; i < m; i++){
        int u, v, c; cin >> u >> v >> c;
        a[u].push_back({v, c});
    }
    auto dijkstra = [&](int st, int ed){
        priority_queue<pll, vector<pll>, greater<pll>> heap;
        heap.push({0, st});
        while (!heap.empty() && cnt[n] < k){
            auto [du, u] = heap.top();
            heap.pop();
            if (u == ed) ans.push_back(du);
            if (++cnt[u] <= k) {
                for (auto [v, c] : a[u]){
                    heap.push({du + c, v});
                }
            }
        }
        for (int i = 0; i < k; i++){
            cout << ans[i] << " \n"[i == k - 1];
        }
    };
    dijkstra(1, n);
    return 0;
}