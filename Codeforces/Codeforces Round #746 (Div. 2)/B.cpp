/**
 *    author:    hungt1
 *    created:   03-10-2021   21:39:55
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
        int n, x; cin >> n >> x;
        vector<int> a(n);
        for (int &val : a) cin >> val;
        vector<bool> mark(n, false);
        vector<int> b = a;
        for (int i = 0; i + x < n; i++){
            mark[i] = mark[i + x] = true;
        }
        sort(all(b));
        bool ans = true;
        for (int i = 0; i < n; i++){
            if (!mark[i] && b[i] != a[i]){
                ans = false;
                break;
            }
        }
        cout << (ans ? "YES\n" : "NO\n");
    }
    return 0;
}