/**
 *    author:    hungt1
 *    created:   26-09-2021   18:05:26
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

const int N = 3e5;

struct FenwickTree {
    int n;
    vector<long> bit;

    FenwickTree(int n = 0) : n(n) {
        bit.resize(n + 1, 0);
    }

    void update(int p, long val){
        for (; p <= n; p += p&-p){
            bit[p] += val;
        }
    }

    long get(int p){
        long ans = 0;
        for (; p > 0; p -= p&-p){
            ans += bit[p];
        }
        return ans;
    }
};

int main()
{
    fastio;
    int n; cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    
    vector<long> f(n), g(n);
    
    vector<FenwickTree> tree(2, FenwickTree (N));

    long sum = 0;
    for (int i = 0; i < n; i++){
        if (i) f[i] = f[i - 1];
        f[i] += 1ll * i * a[i] + sum;
        f[i] -= tree[0].get(a[i]);
        for (int x = 1; ; x++){
            if (x * a[i] > N) break;
            int l = x * a[i];
            int r = min(N, (x + 1) * a[i] - 1);
            tree[0].update(l, 1ll * x * a[i]); tree[0].update(r + 1, -1ll * x * a[i]);
            f[i] -= 1ll * x * a[i] * (tree[1].get(r) - tree[1].get(l - 1));
        }
        sum += a[i]; tree[1].update(a[i], 1);
    }

    for (long x : f) cout << x << ' '; cout << '\n';
    return 0;
}