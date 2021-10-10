/**
 *    author:    hungt1
 *    created:   10-10-2021   17:19:48
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

const int N = 1e3 + 1;

struct pack {
    int x, y, k;
};

vector<pack> a[N];
vector<pack> b[N];
vector<int> posA[N][N], posB[N][N];
long sumA[N], sumB[N];
bool mark[N][N];

int main()
{
    fastio;
    int n, m, q; cin >> n >> m >> q;
    for (int j = 1; j <= m; j++){
        int cur = j;
        for (int i = 1; i <= n; i++){
            a[j].push_back({i, cur, 0});
            posA[i][cur].push_back(j);
            cur++;
            if (cur > m) break;
            a[j].push_back({i, cur, 0});
            posA[i][cur].push_back(j);
        }
    }        
    for (int i = 1; i <= n; i++){
        int cur = i;
        for (int j = 1; j <= m; j++){
            b[i].push_back({cur, j, 0});
            posB[cur][j].push_back(i);
            cur++;
            if (cur > n) break;
            b[i].push_back({cur, j, 0});
            posB[cur][j].push_back(i);
        }
    }
    long tot = n * m;
    for (int i = 1; i <= m; i++){
        int sz = a[i].size();
        tot += 1ll * sz * (sz - 1) / 2;
        sumA[i] = 1ll * sz * (sz - 1) / 2;
    }
    for (int i = 1; i <= n; i++){
        int sz = b[i].size();
        tot += 1ll * sz * (sz - 1) / 2;
        sumB[i] = 1ll * sz * (sz - 1) / 2;
    }

    auto updateA = [&](int x, int y, int id){
        if (id == 0) return;
        for (pack &cur : a[id]){
            if (cur.x == x && cur.y == y){
                cur.k = 1 - cur.k;
            }
        }
        tot -= sumA[id];
        int cnt = 0;
        long tmp = 0;
        for (pack &cur : a[id]){
            if (cur.k == 1){
                tmp += 1ll * cnt * (cnt - 1) / 2;
                cnt = 0;
            }
            else cnt++;
        }
        tmp += 1ll * cnt * (cnt - 1) / 2;
        sumA[id] = tmp; tot += tmp;
    };

    auto updateB = [&](int x, int y, int id){
        for (pack &cur : b[id]){
            if (cur.x == x && cur.y == y){
                cur.k = 1 - cur.k;
            }
        }
        tot -= sumB[id];
        int cnt = 0;
        long tmp = 0;
        for (pack &cur : b[id]){
            if (cur.k == 1){
                tmp += 1ll * cnt * (cnt - 1) / 2;
                cnt = 0;
            }
            else cnt++;
        }
        tmp += 1ll * cnt * (cnt - 1) / 2;
        sumB[id] = tmp; tot += tmp;
    };

    while (q--){
        int x, y; cin >> x >> y;
        if (mark[x][y]) tot++;
        else tot--;
        mark[x][y] = (!mark[x][y]);
        for (int id : posA[x][y]) updateA(x, y, id);
        for (int id : posB[x][y]) updateB(x, y, id);
        cout << tot << '\n';
    }
    return 0;
}