/**
 *    author:    hungt1
 *    created:   12-09-2021   08:28:12
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
        int n, m, a, b; cin >> n >> m >> a >> b;
        cout << "Case #" << test << ": " ;
        if (min(a, b) < n + m - 1) cout << "Impossible\n";
        else {
            cout << "Possible\n";
            for (int i = 0; i < n; i++){
                for (int j = 0; j < m; j++){
                    if (i == 0 && j == 0){
                        cout << a - n - m + 2 << ' ';
                    }
                    else if (i == 0 && j == m - 1){
                        cout << b - n - m + 2 << ' ';
                    }
                    else if (j == 0 || i == n - 1 || j == m - 1){
                        cout << 1 << ' ';
                    }
                    else cout << 1000 << ' ';
                }
                cout << '\n';
            }
        }
    }
    return 0;
}