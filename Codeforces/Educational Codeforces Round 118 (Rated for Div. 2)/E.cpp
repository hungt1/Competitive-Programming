/**
 *    author:    hungt1
 *    created:   01-12-2021   23:23:06
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
        int n, m; cin >> n >> m;
        vector<vector<char>> c(n, vector<char> (m));
        pii start;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                cin >> c[i][j];
                if (c[i][j] == 'L'){
                    start = {i, j};
                }
            }
        }
        vector<vector<bool>> mark(n, vector<bool> (m, false));
        queue<pii> que;
        que.push(start); mark[start.first][start.second] = true;
        
        auto check = [&](int pre_u, int pre_v, int u, int v){
            int cnt = 0;
            for (int i = 0; i < 4; i++){
                int x = u + dx[i];
                int y = v + dy[i];
                if (pii(x, y) == pii(pre_u, pre_v)) continue;
                if (x < 0 || x >= n || y < 0 || y >= m) continue;
                if (c[x][y] == '#') continue;
                if (mark[x][y]) continue;
                cnt++;
            }
            return (cnt <= 1);
        };

        while (!que.empty()){
            int u = que.front().first;
            int v = que.front().second;
            que.pop();
            for (int i = 0; i < 4; i++){
                int x = u + dx[i];
                int y = v + dy[i];
                if (x < 0 || x >= n || y < 0 || y >= m) continue;
                if (c[x][y] == '#') continue;
                if (mark[x][y]) continue;
                if (check(u, v, x, y)){
                    mark[x][y] = true;
                    que.push({x, y});    
                }
            }
        }
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (mark[i][j] && c[i][j] != 'L') cout << '+';
                else cout << c[i][j];
            }
            cout << '\n';
        }
    }
    return 0;
}