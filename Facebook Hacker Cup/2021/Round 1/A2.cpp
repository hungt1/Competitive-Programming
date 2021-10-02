/**
 *    author:    hungt1
 *    created:   12-09-2021   08:23:03
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

int main()
{
    fastio;
    int T; cin >> T;
    for (int test = 1; test <= T; test++){
        int n; string s; cin >> n >> s;
        long ans = 0, sum = 0;
        int cnt = 0, change = -1;
        char pre = ' ';
        for (int i = 0; i < n; i++){
            if (s[i] == 'F') {
                if (pre != ' '){
                    ans += 1ll * change * i - sum - 1ll * cnt * change;
                    ans %= MOD;
                }
                cnt++; continue;
            }
            if (s[i] != pre) {
                change++; pre = s[i];
            }
            ans += 1ll * change * i - sum - 1ll * cnt * change;
            sum += 1ll * change * (cnt + 1); cnt = 0;
            ans %= MOD; sum %= MOD;
        }
        ans = (ans + MOD) % MOD;
        cout << "Case #" << test << ": " << ans << '\n';
    }
    return 0;
}