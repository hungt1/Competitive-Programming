/**
 *    author:    hungt1
 *    created:   23-10-2021   00:38:30
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
        vector<int> a(n);
        vector<long> psum(n + 1, 0);
        for (int i = 0; i < n; i++){
            cin >> a[i];
            psum[i + 1] = psum[i] + a[i];
        }

        auto solve = [&](int l, int r){
            int m = (l + r) / 2;
            long L = 1ll * a[m - 1] * (m - l + 1) - (psum[m] - psum[l - 1]);
            long R = (psum[r] - psum[m - 1]) - 1ll * a[m - 1] * (r - m + 1);
            return L + R;
        };
        
        sort(all(a));
        if (n == 2){
            cout << 0 << '\n';
        }
        else {
            long ans = abs(a[1] - a[0]) + abs(a[n - 1] - a[n - 2]);
            for (int i = 1; i < n; i++){
                if (i == 1){
                    chmin(ans, solve(2, n));
                }
                else if (i == n - 1){
                    chmin(ans, solve(1, n - 1));
                }
                else {
                    long L = a[i - 1] - a[0];
                    long R = a[n - 1] - a[i];
                    chmin(ans, abs(L - R));
                }
            }
            for (int i = 2; i < n - 1; i++){
                long L = a[i] - a[0];
                auto it = upper_bound(a.begin() + 1, a.begin() + i, L - a[n - 1]);
                if (it != (a.begin() + i)){
                    long R = a[n - 1] - (*it);
                    chmin(ans, abs(L - R));
                }
                if (it != (a.begin() + 1)){
                    it--;
                    long R = a[n - 1] - (*it);
                    chmin(ans, abs(L - R));
                }
            }
            cout << ans << '\n';
        }
    }
    return 0;
}