/**
 *    author:    hungt1
 *    created:   02-11-2021   11:42:33
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

int main()
{
    fastio;
    int n, a, b; cin >> n >> a >> b;
    vector<long> sum(n + 1, 0);
    multiset<long> s;
    long ans = -INF;
    for (int i = 1; i <= n; i++){
        int x; cin >> x;
        sum[i] = sum[i - 1] + x;
        if (i - a >= 0) s.insert(sum[i - a]);
        if (i - b - 1 >= 0) s.erase(s.find(sum[i - b - 1]));
        if (s.size()) {
            chmax(ans, sum[i] - (*s.begin())); 
        }
    }
    cout << ans;
    return 0;
}