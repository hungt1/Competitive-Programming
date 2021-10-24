/**
 *    author:    hungt1
 *    created:   11-10-2021   09:32:47
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

const int INF = 2e9 + 3;
const int MOD = 1e9 + 7;
const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

const int N = 22;
map<int, vector<int>> cnt[N];
int sum[1 << N], preMin[N][400001];
string s[N];
int val[N];

int main()
{
    fastio;
    int n; cin >> n;
    for (int i = 0; i < n; i++){
        cin >> s[i];
        int cur = 0, mn = INF;
        for (int j = 0; j < s[i].length(); j++){
            char c = s[i][j];
            cur += (c == ')' ? -1 : 1);
            cnt[i][cur].push_back(j);
            chmin(mn, cur);
            preMin[i][j] = mn;
        }
        val[i] = cur;
        for (int j = 0; j < s[i].length(); j++){
            preMin[i][j] = -preMin[i][j];
        }

    }
    vector<int> dp(1 << n, 0);
    for (int i = 0; i < (1 << n); i++) sum[i] = -INF;
    sum[0] = 0;
    int ans = 0;
    for (int mask = 0; mask < (1 << n); mask++){
        if (sum[mask] < 0) continue;
        for (int i = 0; i < n; i++){
            if (!(mask >> i & 1)){
                int nxt = (mask ^ (1 << i));
                if (sum[mask] - preMin[i][s[i].length() - 1] < 0) {
                    int p = upper_bound(preMin[i], preMin[i] + s[i].length(), sum[mask]) - preMin[i];
                    if (cnt[i].count(-sum[mask])){
                        int add = upper_bound(all(cnt[i][-sum[mask]]), p - 1) - cnt[i][-sum[mask]].begin();
                        chmax(ans, dp[mask] + add);
                    }
                    continue;
                }
                sum[nxt] = sum[mask] + val[i];
                if (cnt[i].count(-sum[mask])){
                    chmax(dp[nxt], dp[mask] + (int)cnt[i][-sum[mask]].size());
                }
                else {
                    chmax(dp[nxt], dp[mask]);
                }
            }
        }
    }
    chmax(ans, *max_element(all(dp)));
    cout << ans << '\n';
    return 0;
}