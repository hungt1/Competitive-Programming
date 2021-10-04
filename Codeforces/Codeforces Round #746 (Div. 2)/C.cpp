/**
 *    author:    hungt1
 *    created:   03-10-2021   22:13:16
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
int val[N];

int main()
{
    fastio;
    int T; cin >> T;
    while (T--){
        int n, k; cin >> n >> k;
        int cnt = 0;
        for (int i = 1; i <= n; i++) cin >> val[i];        
        vector<vector<int>> a(n + 1);
        vector<int> sub(n + 1, 0);
        for (int i = 1; i < n; i++){
            int u, v; cin >> u >> v;
            a[u].push_back(v); a[v].push_back(u);
        }
        
        int need = 0;

        function<void(int, int)> dfs = [&](int p, int u){
            sub[u] = val[u];
            for (int v : a[u]){
                if (v == p) continue;
                dfs(u, v);
                sub[u] ^= sub[v];
            }
            if (sub[u] == need){
                sub[u] = 0;
                cnt++;
            }
        };

        for (int i = 1; i <= n; i++) need = need ^ val[i];
        if (need == 0){
            cout << "YES\n";
        }
        else {
            if (k == 2) cout << "NO\n";
            else {
                dfs(0, 1);
                cout << (cnt > 1 ? "YES\n" : "NO\n");
            }
        }
    }
    return 0;
}