/**
 *    author:    hungt1
 *    created:   16-11-2021   10:15:34
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

const int N = 1e3;
char c[N][N];
int n, m, trace[N][N]; 

int main()
{
    fastio;
    cin >> n >> m;
    pii A, B;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> c[i][j];
            if (c[i][j] == 'A') A = pii(i, j);
            if (c[i][j] == 'B') B = pii(i, j);
        }
    }    
    auto bfs = [&](pii st, pii ed) -> bool {
        queue<pii> que;
        vector<vector<bool>> mark(n, vector<bool> (m, false));
        que.push(st);
        mark[st.first][st.second] = true;
        while (!que.empty()){
            int u = que.front().first;
            int v = que.front().second;
            que.pop();
            for (int i = 0; i < 4; i++){
                int x = u + dx[i];
                int y = v + dy[i];
                if (x < 0 || x == n || y < 0 || y == m) continue;
                if (mark[x][y] || c[x][y] == '#') continue;
                mark[x][y] = true;
                que.push(pii(x, y));
                trace[x][y] = i;
            }
        }
        return mark[ed.first][ed.second];
    };
    if (bfs(A, B)){
        cout << "YES\n";
        int x = B.first, y = B.second;
        string path = "";
        while (x != A.first || y != A.second){
            path += go[trace[x][y]];
            int i = trace[x][y];
            x -= dx[i]; y -= dy[i];
        }
        reverse(all(path));
        cout << path.length() << '\n';
        cout << path << '\n';
    }
    else {
        cout << "NO";
    }
    return 0;
}