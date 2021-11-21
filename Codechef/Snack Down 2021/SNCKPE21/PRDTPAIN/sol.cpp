/**
 *    author:    hungt1
 *    created:   21-11-2021   22:36:36
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

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    
    long ans = 0;
    auto get = [&](int i, int k, int j) -> long {
        return 1ll * (a[j] - a[k]) * (a[k] - a[i]);
    };
    for (int i = 0; i < n; i++){
        int k = i + 1;
        for (int j = i + 2; j < n; j++){
            while (k + 1 < j && get(i, k, j) <= get(i, k + 1, j)) k++;
            ans += get(i, k, j);
        }
    }
    cout << ans << '\n';
}

int main()
{
    fastio;
    int T; cin >> T;
    while (T--){
        solve();
    }
    return 0;
}