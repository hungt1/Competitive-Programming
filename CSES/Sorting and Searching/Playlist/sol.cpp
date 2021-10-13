/**
 *    author:    hungt1
 *    created:   13-10-2021   19:43:02
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

map<int, int> cnt;

int main()
{
    fastio;
    int n; cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    int ans = 1, l = 0;
    for (int r = 0; r < n; r++){
        cnt[a[r]]++;
        while (cnt[a[r]] > 1) cnt[a[l++]]--;
        chmax(ans, r - l + 1);
    }
    cout << ans;
    return 0;
}