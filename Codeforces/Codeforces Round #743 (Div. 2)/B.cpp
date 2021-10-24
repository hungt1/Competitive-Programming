/**
 *    author:    hungt1
 *    created:   18-09-2021   21:42:18
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
        int n; cin >> n;
        vector<int> a(n), b(n);
        for (int &x : a) cin >> x;
        for (int &x : b) cin >> x;
        vector<int> pos(2 * n + 1, 0);
        for (int i = 0; i < n; i++){
            pos[a[i]] = i;
            pos[b[i]] = i;
        }
        for (int i = 2 * n - 2; i >= 1; i--){
            pos[i] = min(pos[i], pos[i + 2]);
        }
        int ans = INF;
        for (int i = 0; i < n; i++){
            chmin(ans, i + pos[a[i] + 1]);
        }
        cout << ans << '\n';
    }
    return 0;
}