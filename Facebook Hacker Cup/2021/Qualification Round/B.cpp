/**
 *    author:    hungt1
 *    created:   28-08-2021   00:46:49
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
        int n; cin >> n;
        vector<vector<char>> a(n, vector<char> (n));
        vector<int> r(n), c(n);
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                cin >> a[i][j];
            }
        }
        int ans = INF, cnt = 0;
        for (int i = 0; i < n; i++){
            int need = 0;
            for (int j = 0; j < n; j++){
                if (a[i][j] == 'O'){
                    need = INF + 1;
                    break;
                }
                else if (a[i][j] == '.') need++;
            }
            if (need < ans){
                ans = need; cnt = 1;
            }
            else if (need == ans) cnt++;
            r[i] = need;
        }
        for (int j = 0; j < n; j++){
            int need = 0;
            for (int i = 0; i < n; i++){
                if (a[i][j] == 'O'){
                    need = INF + 1;
                    break;
                }
                else if (a[i][j] == '.') need++;
            }
            if (need < ans){
                ans = need; cnt = 1;
            }
            else if (need == ans) cnt++;
            c[j] = need;
        }
        if (ans == 1){
            cnt = 0;
            for (int i = 0; i < n; i++){
                for (int j = 0; j < n; j++){
                    if (a[i][j] == '.' && (r[i] == 1 || c[j] == 1)){
                        cnt++;
                    }
                }
            }
        }
        if (ans == INF) cout << "Case #" << test << ": " << "Impossible\n";
        else cout << "Case #" << test << ": " << ans << ' ' << cnt << '\n';       
    }
    return 0;
}