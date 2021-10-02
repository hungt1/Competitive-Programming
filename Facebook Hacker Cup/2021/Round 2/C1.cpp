/**
 *    author:    hungt1
 *    created:   26-09-2021   02:05:39
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

void down(vector<vector<char>> c, int &ans, int n, int m, int k){
    vector<int> cur(m, 0); 
    for (int i = k + 1; i < n; i++){
        for (int j = 0; j < m; j++){
            cur[j] += (c[i][j] == 'X');
        }
    }

    for (int num = 0; num < n; num++){
        int tot = 0;
        for (int j = 0; j < m; j++){
            if (c[k][j] == 'X'){
                tot++;
            }
        }
        chmin(ans, tot + num);
        if (k - num < 0) break;
        for (int j = 0; j < m; j++){
            if (c[k][j] == 'X') cur[j]++;
            if (k - num - 1 >= 0){
                c[k][j] = c[k - num - 1][j];
            }
            else c[k][j] = '.';
            if (cur[j] >= n - k) c[k][j] = 'X';
        }
    }
}

void up(vector<vector<char>>& c, int &ans, int n, int m, int k){
    vector<int> cur(m, 0); 
    for (int i = 0; i < k; i++){
        for (int j = 0; j < m; j++){
            cur[j] += (c[i][j] == 'X');
        }
    }

    for (int num = 0; num < n; num++){
        int tot = 0;
        for (int j = 0; j < m; j++){
            if (c[k][j] == 'X'){
                tot++;
            }
        }
        chmin(ans, tot + num);
        if (k + num == n) break;
        for (int j = 0; j < m; j++){
            if (c[k][j] == 'X') cur[j]++;
            if (k + num + 1 < n){
                c[k][j] = c[k + num + 1][j];
            }
            else c[k][j] = '.';
            if (cur[j] >= k + 1) c[k][j] = 'X';
        }
    }
}

int main()
{
    fastio;
    int T; cin >> T;
    for (int test = 1; test <= T; test++){
        int n, m, k; cin >> n >> m >> k; 
        
        k--;

        vector<vector<char>> c(n, vector<char> (m));

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                cin >> c[i][j];
            }
        }

        int ans = INF;

        down(c, ans, n, m, k); up(c, ans, n, m, k);

        cout << "Case #" << test << ": " << ans << '\n';
    }
    return 0;
}