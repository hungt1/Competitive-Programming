/**
 *    author:    hungt1
 *    created:   17-10-2021   17:27:11
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

void solve(){
    set<pii> ver;
    int n, m; cin >> n >> m;
    vector<int> deg(n + 1, 0), c(n + 1, 0);
    vector<vector<int>> a(n + 1);
    for (int i = 1; i <= m; i++){
        int u, v; cin >> u >> v;
        deg[u]++; deg[v]++;
        a[u].push_back(v); a[v].push_back(u);
    }
    for (int i = 1; i <= n; i++){
        ver.insert({deg[i], i});
    }
    int cnt = n;
    while (!ver.empty()){
        auto it = ver.begin();
        int u = it->second;
        ver.erase(it);
        c[u] = cnt--;
        for (int v : a[u]){
            if (!c[v]){
                ver.erase({deg[v], v});
                deg[v]--;
                ver.insert({deg[v], v});
            }
        }
    }
    int ans = 0;
    for (int u = 1; u <= n; u++){
        int tmp = 0;
        for (int v : a[u]){
            tmp += (c[u] > c[v]);
        }
        chmax(ans, tmp);
    }
    cout << ans << '\n';
    for (int i = 1; i <= n; i++) cout << c[i] << ' ';
    cout << '\n';
}

int main()
{
    fastio;
    int T; cin >> T;
    while (T--){
        solve();
    }
    return 0;
}