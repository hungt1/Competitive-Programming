/**
 *    author:    hungt1
 *    created:   09-11-2021   17:40:38
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

const int N = 5001;
long memo[N][N], pre[N];
int a[N], n;

long dp(int l, int r){
    if (l > r) return 0;
    if (memo[l][r] != -1) return memo[l][r];
    long &cur = memo[l][r];
    cur = max(-dp(l + 1, r), -dp(l, r - 1)) + pre[r] - pre[l - 1];
    return cur;
}

int main()
{
    fastio;
    memset(memo, -1, sizeof(memo));
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    cout << dp(1, n) << '\n';
    return 0;
}