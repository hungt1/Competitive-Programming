/**
 *    author:    hungt1
 *    created:   15-10-2021   00:32:16
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
    while (T--){
        string s; cin >> s;
        int n = s.length();
        vector<vector<int>> pre(2, vector<int> (n + 1, 0));
        for (int i = 0; i < n; i++){
            pre[0][i + 1] = pre[0][i];
            pre[1][i + 1] = pre[1][i];
            pre[i % 2][i + 1] += (s[i] == ')' || s[i] == '(');
        }
        int q; cin >> q;
        while (q--){
            int l, r; cin >> l >> r;
            int even = pre[0][r] - pre[0][l - 1];
            int odd = pre[1][r] - pre[1][l - 1];
            cout << abs(even - odd) << '\n';
        }
    }
    return 0;
}