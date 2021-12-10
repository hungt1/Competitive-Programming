/**
 *    author:    hungt1
 *    created:   01-12-2021   21:53:29
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
const long INF = 1e18;
const int MOD = 1e9 + 7;
const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

void solve(){
    int n; long h; cin >> n >> h;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    long lo = 1, hi = INF;
    long ans = INF;

    auto check = [&](long val){
        long tot = 0;
        for (int i = 0; i < n; i++){
            long add = val;
            if (i + 1 < n) chmin(add, 1ll * a[i + 1] - a[i]);
            tot += add;
            if (tot >= h) return true;
        }
        return false;
    };

    while (lo <= hi){
        long mi = (lo + hi) / 2;
        if (check(mi)){
            ans = mi;
            hi = mi - 1;
        }
        else lo = mi + 1;
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