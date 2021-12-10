/**
 *    author:    hungt1
 *    created:   05-12-2021   22:23:33
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
const long INF = 1e15;
const int MOD = 1e9 + 7;
const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

int main()
{
    fastio;
    int T; cin >> T; 
    while (T--){
        int n, D; cin >> n >> D;
        vector<vector<int>> a(n, vector<int> (n, 0));
        for (int i = 0; i < n; i++){
            for (int j = i + 1; j < n; j++){
                cin >> a[i][j];
                a[j][i] = a[i][j];
            }
        }
        long ans = INF;
        vector<int> cur, rev;
        for (int i = 0; i < n; i++){
            cur.push_back(i);
            vector<int> order(all(cur));
            for (int j = n - 1; j > i; j--){
                order.push_back(j);
            }
            long tmp = 0;
            for (int j = 0; j < n; j++){
                int u = order[j];
                int v = order[(j + 1) % n];
                tmp += 1ll * D * abs(u - v) + a[u][v];
            }
            chmin(ans, tmp);
        }

        for (int i = n - 1; i >= 0; i--){
            rev.push_back(i);
            vector<int> order(all(rev));
            for (int j = 0; j < i; j++){
                order.push_back(j);
            }
            long tmp = 0;
            for (int j = 0; j < n; j++){
                int u = order[j];
                int v = order[(j + 1) % n];
                tmp += 1ll * D * abs(u - v) + a[u][v];
            }
            chmin(ans, tmp);
        }
        cout << ans << '\n';
    }
    return 0;
}