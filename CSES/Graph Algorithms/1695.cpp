/**
 *    author:    hungt1
 *    created:   13-10-2021   20:59:47
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

const int N = 501;
int c[N][N], n, m;
bool visited[N];
vector<int> a[N], ver;

void dfs(int u){
    visited[u] = true;
    ver.push_back(u);
    for (int v : a[u]){
        if (!visited[v] && c[u][v] > 0){
            dfs(v);
        }
    }
}

void minCut(){
    dfs(1);
    for (int u : ver){
        for (int v : a[u]){
            if (visited[v]) continue;
            if (c[u][v] <= 0){
                cout << u << ' ' << v << '\n';
            }
        }
    }
}

int bfs(int s, int t, vector<int> &p){
    fill(p.begin(), p.end(), 0);
    queue<pii> que;
    que.push(pii(s, INF));
    p[s] = -1;
    while (!que.empty()){
        int u = que.front().first;
        int cur = que.front().second;
        que.pop();
        for (int v : a[u]){
            int w = c[u][v];
            if (p[v] != 0 || c[u][v] <= 0) continue;
            int d = min(w, cur);
            p[v] = u;
            if (v == t) return d;
            que.push(pii(v, d));
        }
    }
    return 0;
}

int maxFlow(int s, int t){
    int ans = 0, add = 0;
    vector<int> p(n + 1);
    while (add = bfs(s, t, p)){
        ans += add;
        int cur = t, pre;
        while (cur != s){
            pre = p[cur];
            c[pre][cur] -= add;
            c[cur][pre] += add;
            cur = pre;
        }
    }
    return ans;
}

int main()
{
    fastio;
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        c[u][v] = c[v][u] = 1;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    cout << maxFlow(1, n) << '\n';
    minCut();
    return 0;
}