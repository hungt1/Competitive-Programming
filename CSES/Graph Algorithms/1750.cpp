/**
 *    author:    hungt1
 *    created:   14-12-2021   10:24:23
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

const int N = 2e5 + 1;
int par[31][N];

int main()
{
    fastio;
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++){
        cin >> par[0][i];
    }
    for (int i = 1; i < 31; i++){
        for (int u = 1; u <= n; u++){
            par[i][u] = par[i - 1][par[i - 1][u]];
        }
    }
    auto query = [&](int u, int k){
        for (int i = 0; i < 31; i++){
            if (k >> i & 1){
                u = par[i][u];
            }
        }
        return u;
    };
    while (q--){
        int x, k; cin >> x >> k;
        cout << query(x, k) << '\n';
    }
    return 0;
}