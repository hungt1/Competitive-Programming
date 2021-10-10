/**
 *    author:    hungt1
 *    created:   10-10-2021   16:30:44
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

map<long, int> cnt;

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    long sum = 0;
    for (int &x : a){
        cin >> x;
        sum += x;
    }
    cnt.clear();
    if (2 * sum % n){
        cout << 0 << '\n';
        return;
    }
    long need = 2 * sum / n;
    long ans = 0;
    for (int x : a){
        ans += cnt[need - x];
        cnt[x]++;
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