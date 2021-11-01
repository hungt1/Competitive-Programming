/**
 *    author:    hungt1
 *    created:   01-11-2021   18:08:58
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
const long INF = 1e15;
const int MOD = 1e9 + 7;
const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

int main()
{
    fastio;
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    auto check = [&](long val) -> bool{
        int cnt = 1;
        long sum = 0;
        for (int i = 0; i < n; i++){
            if (a[i] > val) return false;
            sum += a[i];
            if (sum > val){
                sum = a[i];
                cnt++;
            }
        }
        return (cnt <= k);
    };

    long lo = 1, hi = INF;
    long ans = INF;
    while (lo <= hi){
        long mi = (lo + hi) / 2;
        if (check(mi)){
            ans = mi;
            hi = mi - 1;
        }
        else lo = mi + 1;
    } 
    cout << ans << '\n';
    return 0;
}