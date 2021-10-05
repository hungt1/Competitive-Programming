/**
 *    author:    hungt1
 *    created:   03-10-2021   13:24:39
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

int ans = 0;
bool mark[9][9];

inline void solve(int u, int v, int cur, string &s){
    if (u == 7 && v == 1){
        ans += (cur == 48);
        return;
    }
    if (!mark[u - 1][v] && !mark[u + 1][v] && mark[u][v - 1] && mark[u][v + 1]) return;
    if (mark[u - 1][v] && mark[u + 1][v] && !mark[u][v - 1] && !mark[u][v + 1]) return;
    mark[u][v] = true;
    if (s[cur] != '?'){
        int x = u - (s[cur] == 'U') + (s[cur] == 'D');
        int y = v - (s[cur] == 'L') + (s[cur] == 'R');
        if (!mark[x][y]) solve(x, y, cur + 1, s);
    }
    else {
        for (int i = 0; i < 4; i++){
            int x = u + dx[i];
            int y = v + dy[i];
            if (!mark[x][y]) solve(x, y, cur + 1, s);
        }
    }
    mark[u][v] = false;
}

int main()
{
    fastio;
    string s; cin >> s;
    memset(mark, true, sizeof(mark));
    for (int i = 1; i <= 7; i++){
        for (int j = 1; j <= 7; j++){
            mark[i][j] = false;
        }
    }
    solve(1, 1, 0, s);
    cout << ans << '\n';
    return 0;
}