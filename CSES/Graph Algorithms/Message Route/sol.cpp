/**
 *    author:    hungt1
 *    created:   16-11-2021   10:59:38
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

const int N = 1e5 + 1;
vector<int> a[N];
int dis[N], trace[N];

int main()
{
    fastio;
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);        
    }
    
    auto bfs = [&](int st){
        queue<int> que;
        que.push(st);
        memset(dis, -1, sizeof(int) * (n + 1));
        memset(trace, -1, sizeof(int) * (n + 1));
        dis[st] = 0;
        while (!que.empty()){
            int u = que.front();
            que.pop();
            for (int v : a[u]){
                if (dis[v] == -1){
                    dis[v] = dis[u] + 1;
                    que.push(v);
                    trace[v] = u;
                }
            } 
        }

    };
    
    bfs(1);
    if (dis[n] == -1) cout << "IMPOSSIBLE";
    else {
        cout << dis[n] + 1 << '\n';
        vector<int> path;
        for (int u = n; u != -1; u = trace[u]){
            path.push_back(u);
        }
        reverse(all(path));
        for (int x : path) cout << x << ' ';
    }
    return 0;
}