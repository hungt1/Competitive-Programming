/**
 *    author:    hungt1
 *    created:   28-10-2021   23:58:55
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

const int N = 3e5 + 1;
int a[N], b[N], dist[N];
int trace[N], pre[N];

int main()
{
    fastio;
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    set<int> s;
    for (int i = 0; i < n; i++) s.insert(i);
    queue<int> que;
    memset(dist, 0x3c, sizeof(dist));
    memset(trace, -1, sizeof(trace));
    que.push(n); 
    trace[n] = -2; dist[n] = 0;
    while (!que.empty()){
        int u = que.front();
        que.pop();
        auto it = s.lower_bound(u - a[u]);
        vector<int> val;
        while (it != s.end()){
            int i = *it++;
            if (i > u) break;
            val.push_back(i);
            int v = i + b[i];
            if (trace[v] == -1){
                dist[v] = dist[u] + 1;
                trace[v] = u;
                pre[v] = i;
                que.push(v);
            }
        }
        for (int x : val) s.erase(x);
    }
    if (trace[0] == -1) return cout << -1, 0;
    vector<int> path;
    for (int x = 0; x != n; x = trace[x]){
        path.push_back(pre[x]);
    }
    reverse(all(path));
    cout << dist[0] << '\n';
    for (int x : path) cout << x << ' ';
    return 0;
}