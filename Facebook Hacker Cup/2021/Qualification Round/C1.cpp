/**
 *    author:    hungt1
 *    created:   28-08-2021   01:12:16
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

const int N = 51;
vector<int> a[N];
int F[N], c[N];

void dfs(int p, int u){
    F[u] = c[u];
    for (int v : a[u]){
        if (v == p) continue;
        dfs(u, v);
        chmax(F[u], F[v] + c[u]);
    }
}

int main()
{
    fastio;
    int T; cin >> T;
    for (int test = 1; test <= T; test++){
        int n; cin >> n;
        for (int i = 1; i <= n; i++) cin >> c[i];
        for (int i = 1; i <= n; i++) a[i].clear();
        for (int i = 1; i < n; i++){
            int u, v; cin >> u >> v;
            a[u].push_back(v); a[v].push_back(u);
        }
        dfs(0, 1);
        vector<int> val;
        for (int x : a[1]) val.push_back(F[x]);
        sort(all(val), greater<int> ());
        int ans = 0;
        if (val.size() < 2){
            ans = F[1];
        }
        else ans = val[0] + val[1] + c[1];;
        cout << "Case #" << test << ": " << ans << '\n';
    }
    return 0;
}