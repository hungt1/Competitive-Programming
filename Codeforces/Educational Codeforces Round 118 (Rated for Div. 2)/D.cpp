/**
 *    author:    hungt1
 *    created:   01-12-2021   22:05:41
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
const int MOD = 998244353;
const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

int power(int x, int n){
    if (n == 0) return 1;
    int y = power(x, n / 2);
    y = 1ll * y * y % MOD;
    if (n & 1) return 1ll * x * y % MOD;
    else return y;
}

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    int cnt = 0;
    for (int &x : a){
        cin >> x; 
        if (x == 1) cnt++;
    }
    int ans = 0;
    vector<vector<int>> f(3, vector<int> (n + 1, 0));
    vector<vector<int>> dp(3, vector<int> (n, 0));
    for (int i = 0; i < n; i++){
        if (a[i] == 0) dp[0][i] = 1;
    }

    auto get = [&](int p, int i){
        if (i < 0 || i > n) return 0;
        return f[p][i];
    };

    auto update = [&](int p, int i, int val){
        if (i < 0 || i > n) return;
        f[p][i] += val; f[p][i] %= MOD;
    };

    for (int i = 0; i < n; i++){
        dp[0][i] += get(0, a[i] - 1) + get(0, a[i]) % MOD;
        dp[0][i] %= MOD;
    
        dp[1][i] += (get(1, a[i]) + get(0, a[i] - 2)) % MOD;
        dp[1][i] %= MOD;
        dp[1][i] += get(2, a[i] - 2);
        dp[1][i] %= MOD;
        
        dp[2][i] += (get(1, a[i] + 2) + get(2, a[i])) % MOD; 
        dp[2][i] %= MOD;

        (ans += (dp[0][i] + dp[1][i]) % MOD) %= MOD;
        ans = (ans + dp[2][i]) % MOD;

        update(0, a[i], dp[0][i]); 
        update(1, a[i], dp[1][i]);
        update(2, a[i], dp[2][i]);
    }
    ans = (ans + power(2, cnt) - 1) % MOD;
    cout << (ans + MOD) % MOD << '\n';
}

int main()
{
    fastio;
    int T; cin >> T;
    while (T--){
        solve();
    }
    return 0;
}