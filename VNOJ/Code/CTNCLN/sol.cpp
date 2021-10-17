/**
 *    author:    hungt1
 *    created:   11-10-2021   18:50:33
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

const int N = 4e4 + 1;
int cnt[N], a[N];
int dp[N];

int main()
{
    fastio;
    int n,  m; cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }  
    int lim = min(m, (int)sqrt(n));
    vector<vector<int>> pos(lim + 1, vector<int> (n + 1, -1));
    for (int d = 1; d <= lim; d++){
        memset(cnt, 0, sizeof(int) * (n + 1));
        int j = 1;
        int num = 0;
        for (int i = 1; i <= n; i++){
            if (!cnt[a[i]]++) num++;
            while (num > d){
                if (--cnt[a[j++]] == 0) num--;
            }
            if (num == d){
                pos[d][i] = j - 1;
            }
        }
    }
    memset(dp, 0x3c, sizeof(int) * (n + 1));
    dp[0] = 0;
    for (int i = 1; i <= n; i++){
        for (int d = 1; d <= lim; d++){
            if (pos[d][i] != -1){
                if (d * d > dp[i]) break;
                chmin(dp[i], dp[pos[d][i]] + d * d);
            }
        }
    }   
    cout << dp[n] << '\n';
    return 0;
}