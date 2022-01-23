/**
 *    author:    hungt1
 *    created:   08-10-2021   00:59:07
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
    int n, m; cin >> n >> m;
    vector<int> pos(n + 1), val(n);
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        pos[x] = i; val[i] = x;
    }
    int ans = 1;
    for (int i = 2; i <= n; i++){
        ans += (pos[i] < pos[i - 1]);
    }
    auto cost = [&](int i){
        int ans = 0;
        if (i > 1 && pos[i] < pos[i - 1]) ans++;
        if (i < n && pos[i + 1] < pos[i]) ans++;
        return ans;
    };
    while (m--){
        int x, y; cin >> x >> y;
        int a = val[x - 1], b = val[y - 1];
        if (a > b) swap(a, b);
        if (a == b){
            cout << ans << '\n';
            continue;
        }
        ans -= cost(a) + cost(b);
        if (a + 1 == b && pos[a] > pos[b]) ans++;
        swap(pos[a], pos[b]);
        ans += cost(a) + cost(b);
        if (a + 1 == b && pos[a] > pos[b]) ans--;
        swap(val[x - 1], val[y - 1]);
        cout << ans << '\n';
    }
    return 0;
}