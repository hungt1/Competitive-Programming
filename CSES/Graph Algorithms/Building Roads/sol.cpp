/**
 *    author:    hungt1
 *    created:   16-11-2021   10:54:45
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
bool mark[N];

void dfs(int u){
    mark[u] = true;
    for (int v : a[u]){
        if (mark[v]) continue;
        dfs(v);
    }
}
int main()
{
    fastio;
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int u, v; cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }   
    vector<int> ans;
    for (int i = 1; i <= n; i++){
        if (!mark[i]){
            ans.push_back(i);
            dfs(i);
        }
    }
    cout << ans.size() - 1 << '\n';
    for (int i = 1; i < ans.size(); i++){
        cout << ans[i] << ' ' << ans[i - 1] << '\n';
    }
    return 0;
}