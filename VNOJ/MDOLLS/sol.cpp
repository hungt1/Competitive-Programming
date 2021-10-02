/**
 *    author:    hungt1
 *    created:   04-09-2021   15:58:33
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

struct FenwickTree {
    int n;
    vector<int> bit;

    FenwickTree() {
        n = 0;
    }

    FenwickTree(int n) : n(n) {
        bit.assign(n + 1, 0);
    }

    void update(int p, int val){
        for (; p > 0; p -= p&-p){
            chmax(bit[p], val);
        }
    }

    int get(int p){
        int ans = 0;
        for (; p <= n; p += p&-p){
            chmax(ans, bit[p]);
        }
        return ans;
    }
};


void solve(){
    int n; cin >> n;
    vector<pii> a(n);
    for (pii &x : a) cin >> x.first >> x.second;
    sort(all(a), [&](const pii &cur, const pii &other){
        return (cur.first == other.first ? cur.second > other.second : cur.first < other.first); 
    });
    FenwickTree tree(10000);
    int ans = 0;
    for (pii &x : a){
        int cur = tree.get(x.second);
        chmax(ans, cur + 1);
        tree.update(x.second, cur + 1);
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