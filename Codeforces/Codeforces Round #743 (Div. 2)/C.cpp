/**
 *    author:    hungt1
 *    created:   18-09-2021   21:59:33
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
    int T; cin >> T;
    while (T--){
        int n; cin >> n;
        vector<vector<int>> a(n + 1);
        vector<int> deg(n + 1, 0);
        for (int i = 1; i <= n; i++){
            int m; cin >> m;
            while (m--){
                int j; cin >> j;
                a[j].push_back(i);
                deg[i]++;
            }
        }
        vector<int> cnt(n + 1, 0);
        int num = 0;
        queue<int> que;
        for (int i = 1; i <= n; i++){
            if (deg[i] == 0){
                que.push(i);
                cnt[i] = 1;
            }
        }
        while (!que.empty()){
            int u = que.front();
            que.pop();
            num++;
            for (int v : a[u]){
                deg[v]--;
                chmax(cnt[v], cnt[u] + (v < u));
                if (deg[v] == 0){
                    que.push(v);
                }
            }
        }
        if (num != n){
            cout << -1 << '\n';
        }
        else cout << *max_element(all(cnt)) << '\n';
    }
    return 0;
}