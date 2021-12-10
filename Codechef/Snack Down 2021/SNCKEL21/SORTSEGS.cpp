/**
 *    author:    hungt1
 *    created:   05-12-2021   21:41:29
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
        int n, k; cin >> n >> k;
        vector<int> a(n);
        for (int &x : a) cin >> x;
        vector<int> b(all(a));
        sort(all(b));
        if (a == b){
            cout << 0 << '\n';
        }
        else {
            auto check = [&](int u, int v, int x, int y, vector<int> val) -> bool{
                sort(val.begin() + u, val.begin() + v + 1);
                sort(val.begin() + x, val.begin() + y + 1);
                return (val == b);
            };
            int l = 0, r = n - 1;
            while (l < n && a[l] == b[l]) l++;
            while (r >= 0 && a[r] == b[r]) r--;
            if (r - l + 1 <= k){
                cout << 1 << '\n';
                continue;
            }
            if (check(l, l + k - 1, r - k + 1, r, a)){
                cout << 2 << '\n';
                continue;
            }
            if (check(r - k + 1, r, l, l + k - 1, a)){
                cout << 2 << '\n';
                continue;
            }
            cout << 3 << '\n';
        }
    }
    return 0;
}