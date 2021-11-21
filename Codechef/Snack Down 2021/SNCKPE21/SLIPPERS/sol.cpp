/**
 *    author:    hungt1
 *    created:   21-11-2021   23:45:25
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
const int MOD = 998244353;
const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

struct FenwickTree {
    int n;
    vector<int> bit;

    FenwickTree(int n = 0) : n(n) {
        bit.resize(n + 1, 0);
    }

    void update(int p, int val){
        for (; p <= n; p += p&-p){
            bit[p] += val;
            bit[p] %= MOD;
        }
    }

    int get(int p){
        int ans = 0;
        for (; p > 0; p -= p&-p){
            ans += bit[p];
            ans %= MOD;
        }
        return ans;
    }
};

int main()
{
    fastio;
    int n; cin >> n;
    FenwickTree tree(200000);
    int ans = 0;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        int cur = tree.get(x - 1) + 1;
        tree.update(x, cur);
        (ans += cur) %= MOD;
    }
    cout << (ans + 1) % MOD;
    return 0;
}