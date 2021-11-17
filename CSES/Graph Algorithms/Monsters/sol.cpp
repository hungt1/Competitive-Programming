/**
 *    author:    hungt1
 *    created:   17-11-2021   11:01:38
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
const char go[4] = {'L', 'R', 'U', 'D'};

int main()
{
    fastio;
    int n, m; cin >> n >> m;
    vector<vector<char>> c(n, vector<char> (m));
    vector<pii> monsters;
    pii st;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> c[i][j];
            if (c[i][j] == 'M') monsters.push_back({i, j});
            if (c[i][j] == 'A') st = pii(i, j);
        }
    }
    
    vector<vector<int>> trace(n, vector<int> (m, -1));
    vector<vector<int>> visited(n, vector<int> (m, 0));
    queue<pii> que;
    for (auto [u, v] : monsters){
        visited[u][v] = 2;
        que.push({u, v});
    }
    visited[st.first][st.second] = 1;
    que.push(st);
    while (!que.empty()){
        auto [u, v] = que.front();
        que.pop();
        for (int i = 0; i < 4; i++){
            int x = u + dx[i];
            int y = v + dy[i];
            if (x < 0 || x == n || y < 0 || y == m) continue;
            if (visited[x][y] || c[x][y] != '.') continue;
            trace[x][y] = i; visited[x][y] = visited[u][v];
            que.push({x, y});
        }
    }
    
    auto print = [&](int u, int v) -> string{
        string ans = "";
        while (u != st.first || v != st.second){
            ans += go[trace[u][v]];
            int i = trace[u][v];
            u -= dx[i]; v -= dy[i];
        }
        reverse(all(ans));
        cout << "YES\n" << ans.length() << '\n';
        return ans;
    };

    for (int i = 0; i < n; i++){
        if (visited[i][0] == 1) return cout << print(i, 0), 0;
        if (visited[i][m - 1] == 1) return cout << print(i, m - 1), 0;
    }
    for (int i = 0; i < m; i++){
        if (visited[0][i] == 1) return cout << print(0, i), 0;
        if (visited[n - 1][i] == 1) return cout << print(n - 1, i), 0;
    }
    cout << "NO";
    return 0;
}