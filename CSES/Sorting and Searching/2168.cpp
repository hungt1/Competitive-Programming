/**
 *    author:    hungt1
 *    created:   17-10-2021   20:07:50
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

struct pack {
    int l, r, id;
};

int main()
{
    fastio;
    int n; cin >> n;
    vector<pack> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i].l >> a[i].r;
        a[i].id = i;
    }
    vector<vector<int>> ans(2, vector<int> (n));
    sort(all(a), [](const pack& cur, const pack& other){
        return (cur.r == other.r ? cur.l > other.l : cur.r < other.r);
    });
    set<int> p;
    for (pack &cur : a){
        if (!p.empty()){
            if (p.lower_bound(cur.l) != p.end()){
                ans[0][cur.id] = 1;
            }
        }
        p.insert(cur.l);
    }
    p.clear();
    sort(all(a), [](const pack& cur, const pack& other){
        return (cur.r == other.r ? cur.l < other.l : cur.r > other.r);
    });
    for (pack &cur : a){
        if (!p.empty()){
            if (p.upper_bound(cur.l) != p.begin()){
                ans[1][cur.id] = 1;
            }
        }
        p.insert(cur.l);
    }
    for (int i = 0; i < n; i++){
        cout << ans[0][i] << " \n"[i == n - 1];
    }
    for (int i = 0; i < n; i++){
        cout << ans[1][i] << " \n"[i == n - 1];
    }
    return 0;
}