/**
 *    author:    hungt1
 *    created:   26-09-2021   00:58:42
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

const int N = 8e5 + 1;
vector<int> a[N];
map<int, int> dp[N];
int ans = 0, c[N];
int num[N], cnt[N];

void dfs(int p, int u){
    for (int v : a[u]){
        if (v == p) continue;
        dfs(u, v);
        num[u] += num[v];
        if (dp[u].size() < dp[v].size()) swap(dp[u], dp[v]);
        for (auto x : dp[v]) {
            int pre = dp[u][x.first];
            dp[u][x.first] += x.second;
            if (pre != 0 && dp[u][x.first] == cnt[x.first]) num[u]++;
        }
    }
    dp[u][c[u]]++;
    if (dp[u][c[u]] == cnt[c[u]]) num[u]++;
    if (u != 1 && num[u] == dp[u].size()) ans++;
}

int main()
{
    fastio;
    int T; cin >> T;
    for (int test = 1; test <= T; test++){
        int n; cin >> n;
        
        for (int i = 1; i <= n; i++) {
            a[i].clear(); dp[i].clear();
            cnt[i] = num[i] = 0;
        }

        for (int i = 1; i < n; i++){
            int u, v; cin >> u >> v;
            a[u].push_back(v); a[v].push_back(u);
        }
        for (int i = 1; i <= n; i++) {
            cin >> c[i]; 
            cnt[c[i]]++;
        }       
        ans = 0;
        dfs(0, 1);
        cout << "Case #" << test << ": " << ans << '\n';
    }
    return 0;
}