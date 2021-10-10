/**
 *    author:    hungt1
 *    created:   09-10-2021   17:56:56
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

const int N = 2e3 + 1;
int n, sum[N];
int opt[N][N], dp[N][N];

int main()
{
    fastio;
    int n; cin >> n;
    for (int i = 1; i <= n; i++){
        int x; cin >> x;
        sum[i] = sum[i - 1] + x;
    }

    for (int i = 1; i <= n; i++){
        dp[i][i] = 0;
        opt[i][i] = i;
        for (int j = i + 1; j <= n; j++){
            dp[i][j] = -INF;
        }
    }

    for (int i = n - 1; i >= 1; i--){
        for (int j = i + 1; j <= n; j++){
            for (int k = opt[i][j - 1]; k <= opt[i + 1][j]; k++){
                int val = min(dp[i][k] + sum[k] - sum[i - 1], dp[k + 1][j] + sum[j] - sum[k]);
                if (dp[i][j] < val){
                    dp[i][j] = val;
                    opt[i][j] = k;
                }
            }
        }
    }

    cout << dp[1][n];
    return 0;
}