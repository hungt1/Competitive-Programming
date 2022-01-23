/**
 *    author:    hungt1
 *    created:   09-11-2021   21:11:26
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

const int N = 20;
vector<int> digit;
long memo[N][2][2][10];

long dp(int i, bool st, bool lss, int pre){
    if (i == (int)digit.size()) return 1;
    if (memo[i][st][lss][pre] != -1) return memo[i][st][lss][pre];
    long ans = 0;
    for (int d = 0; d < 10; d++){
        if (lss == false && d > digit[i]) continue;
        if (st && pre == d) continue;
        ans += dp(i + 1, st || (d != 0), lss || (d < digit[i]), d);
    }
    return memo[i][st][lss][pre] = ans;
}
long solve(long x){
    if (x <= 0) return (x == 0);
    digit.clear();
    for (; x > 0; x /= 10) digit.push_back(x % 10);
    reverse(all(digit));
    memset(memo, -1, sizeof(memo));
    return dp(0, 0, 0, 0);
}

int main()
{
    fastio;
    long a, b; cin >> a >> b;
    cout << solve(b) - solve(a - 1);    
    return 0;
}