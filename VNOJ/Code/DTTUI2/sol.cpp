/**
 *    author:    hungt1
 *    created:   29-09-2021   15:31:15
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
    int n, m; cin >> n >> m;
    vector<pii> stones;
    for (int i = 0; i < n; i++){
        int w, v, a; cin >> w >> v >> a;
        for (int j = 0; (1 << j) <= a; j++){
            int num = 1 << j;
            stones.push_back({w * num, v * num});
            a -= num;
        }
        if (a > 0) stones.push_back({w * a, v * a});
    }   
    vector<int> dp(m + 1, -INF);
    dp[0] = 0;
    for (pii x : stones){
        for (int i = m; i >= x.first; i--){
            chmax(dp[i], dp[i - x.first] + x.second);
        }
    }
    cout << *max_element(all(dp));
    return 0;
}