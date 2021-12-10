/**
 *    author:    hungt1
 *    created:   11-12-2021   01:02:44
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
    vector<int> deg(n + 1, 0);
    for (int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        a[u].push_back(v);
        deg[v]++;
    }
    queue<int> que;
    for (int u = 1; u <= n; u++){
        if (deg[u] == 0) que.push(u);
    }
    vector<int> order;
    while (!que.empty()){
        int u = que.front();
        que.pop();
        order.push_back(u);
        for (int v : a[u]){
            deg[v]--;
            if (deg[v] == 0){
                que.push(v);
            }
        }
    }
    if (order.size() != n){
        cout << "IMPOSSIBLE\n";
    }
    else {
        for (int i = 0; i < n; i++){
            cout << order[i] << " \n"[i == n - 1];
        }
    }
    return 0;
}