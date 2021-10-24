/**
 *    author:    hungt1
 *    created:   09-08-2021   10:20:19
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
        int n, m, k; cin >> n >> m >> k;
        vector<vector<char>> ans(n, vector<char> (m + 1));
        if ((m / 2) * n < k){
            cout << "NO\n";
            continue;
        }
        if (n % 2 == 0 && k % 2 == 0){
            cout << "YES\n";
            char a = 'a', b = 'b';
            char c = 'c', d = 'd';
            
            for (int j = 0; j < m; j += 2){
                for (int i = 0; i < n; i += 2){
                    if (j > 0 && ans[i][j - 1] == c){
                        swap(c, d);
                    }
                    ans[i][j] = ans[i + 1][j] = c;
                    ans[i][j + 1] = ans[i + 1][j + 1] = d;
                    swap(c, d);
                }
            }

            for (int j = 0; j < m; j += 2){
                for (int i = 0; i < n; i += 2){
                    if (k > 0){
                        if (j > 0 && ans[i][j - 1] == a){
                            swap(a, b);
                        }
                        ans[i][j] = ans[i][j + 1] = a;
                        ans[i + 1][j] = ans[i + 1][j + 1] = b;
                        k -= 2;
                    }
                }
            }
            for (int i = 0; i < n; i++){
                for (int j = 0; j < m; j++){
                    cout << ans[i][j];
                }
                cout << '\n';
            }
        }
        else if (n % 2 == 0){
            cout << "NO\n";
        } 
        else {
            int x = k - (m / 2);
            if (x < 0 || x % 2){
                cout << "NO\n";
            }
            else {
                cout << "YES\n";
                char x = 'x', y = 'y';
                for (int i = 0; i < m; i += 2, k--){
                    ans[n - 1][i] = ans[n - 1][i + 1] = x;
                    swap(x, y);
                }
                char a = 'a', b = 'b';
                char c = 'c', d = 'd';
                for (int j = 0; j < m; j += 2){
                    for (int i = 0; i < n - 1; i += 2){
                        if (j > 0 && ans[i][j - 1] == c){
                            swap(c, d);
                        }
                        ans[i][j] = ans[i + 1][j] = c;
                        ans[i][j + 1] = ans[i + 1][j + 1] = d;
                        swap(c, d);
                    }
                }

                for (int j = 0; j < m; j += 2){
                    for (int i = 0; i < n - 1; i += 2){
                        if (k > 0){
                            if (j > 0 && ans[i][j - 1] == a){
                                swap(a, b);
                            }
                            ans[i][j] = ans[i][j + 1] = a;
                            ans[i + 1][j] = ans[i + 1][j + 1] = b;
                            k -= 2;
                        }
                    }
                }

                for (int i = 0; i < n; i++){
                    for (int j = 0; j < m; j++){
                        cout << ans[i][j];
                    }
                    cout << '\n';
                }
            }
        }
    }
    return 0;
}