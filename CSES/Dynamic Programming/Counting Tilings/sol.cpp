/**
 *    author:    hungt1
 *    created:   09-11-2021   20:38:18
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

vector<int> valid;
vector<int> adj[1 << 10];
int n, m;

bool check(int mask){
    int cnt = 0;
    for (int i = 0; i < n; i++){
        if (mask >> i & 1) cnt++;
        else {
            if (cnt % 2) return false;
            cnt = 0;
        }
    }
    return (cnt % 2 == 0);
}

int main()
{
    fastio;
    cin >> n >> m;
    for (int mask = 0; mask < (1 << n); mask++){
        if (check(mask)){
            valid.push_back(mask);
        }
    }
    int last = (1 << n) - 1;
    for (int mask = 0; mask < (1 << n); mask++){
        int orz = mask ^ last;
        for (int nxt = 0; nxt < (1 << n); nxt++){
            if ((orz & nxt) == orz){
                if (check(orz ^ nxt)){
                    adj[mask].push_back(nxt);
                }
            }
        }
    }
    vector<int> dp(1 << n, 0);
    for (int mask : valid) dp[mask] = 1;
    for (int i = 2; i <= m; i++){
        vector<int> tmp(1 << n, 0);
        for (int mask = 0; mask < (1 << n); mask++){
            if (dp[mask]){
                for (int nxt : adj[mask]){
                    tmp[nxt] += dp[mask];
                    tmp[nxt] %= MOD;
                }
            }
        }
        swap(tmp, dp);
    }
    cout << dp[last];
    return 0;
}