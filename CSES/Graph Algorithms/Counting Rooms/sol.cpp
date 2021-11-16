/**
 *    author:    hungt1
 *    created:   09-11-2021   21:35:53
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
    vector<vector<char>> c(n, vector<char> (m));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> c[i][j];
        }
    }
    vector<vector<bool>> mark(n, vector<bool> (m, false));
    int cnt = 0;
    auto bfs = [&](int i, int j){
        queue<pii> que;
        que.push({i, j});
        mark[i][j] = true;
        while (!que.empty()){
            int u = que.front().first;
            int v = que.front().second;
            que.pop();
            for (int k = 0; k < 4; k++){
                int x = u + dx[k];
                int y = v + dy[k];
                if (x < 0 || x == n || y < 0 || y == m) continue;
                if (c[x][y] == '#' || mark[x][y]) continue;
                mark[x][y] = true;
                que.push({x, y});
            }
        }
    };
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (c[i][j] == '.' && !mark[i][j]){
                bfs(i, j); cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}