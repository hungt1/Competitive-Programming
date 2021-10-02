/**
 *    author:    hungt1
 *    created:   25-09-2021   23:59:39
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
    for (int test = 1; test <= T; test++){
        int n, m; cin >> n >> m;
        vector<pii> a(m);
        for (int i = 0; i < m; i++){
            cin >> a[i].first;
            a[i].second = 1;
        }

        int ans = 0;
        for (int i = 0; i < n; i++){
            multiset<int> cur;
            vector<bool> mark(m);
            sort(all(a));
            for (int j = 0; j < m; j++){
                int x; cin >> x;
                cur.insert(x);
            }
            for (int j = 0; j < m; j++){
                auto it = cur.lower_bound(a[j].first);
                if (it != cur.end() && *it == a[j].first){
                    mark[j] = true;
                    cur.erase(it);
                }
            }
            for (int j = 0; j < m; j++){
                if (!mark[j]){
                    auto it = cur.begin();
                    a[j].first = *it;
                    cur.erase(it);
                    if (a[j].second) a[j].second--;
                    else ans++;
                }
            }
        }        
        cout << "Case #" << test << ": " << ans << '\n';
    }
    return 0;
}