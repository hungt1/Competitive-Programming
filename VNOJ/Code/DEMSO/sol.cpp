/**
 *    author:    hungt1
 *    created:   06-10-2021   00:05:42
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

const int N = 21;
long memo[N][2][N][11];
vector<int> digits;
long D, K;

long dp(int i, bool lss, int last, int k){
    if (i == (int)digits.size()) return 1;
    if (memo[i][lss][k][last] != -1) return memo[i][lss][k][last];
    long ans = 0;
    for (int d = 0; d < 10; d++){
        if (!lss && (d > digits[i])) continue;
        int cost = (last == 10 ? 0 : (abs(last - d) <= D));
        if (k + cost > K) continue;
        ans += dp(i + 1, lss | (d < digits[i]), ((last == 10 && d == 0) ? last : d), k + cost);
    }
    return memo[i][lss][k][last] = ans;
}

long F(long x){
    memset(memo, -1, sizeof(memo));
    digits.clear();
    for (; x > 0; x /= 10) digits.push_back(x % 10);
    reverse(all(digits));
    if (digits.size() == 0) digits.push_back(0);
    return dp(0, 0, 10, 0);
}

int main()
{
    fastio;
    long A, B; cin >> A >> B >> D >> K;
    cout << F(B) - F(A - 1) << '\n';
    return 0;
}