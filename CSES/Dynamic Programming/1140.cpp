/**
 *    author:    hungt1
 *    created:   09-11-2021   19:47:13
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
    vector<long> bit;

    FenwickTree(int n = 0) : n(n) {
        bit.resize(n + 1, 0);
    }

    void update(int p, long val){
        for (; p <= n; p += p&-p){
            chmax(bit[p], val);
        }
    }

    long get(int p){
        long ans = 0;
        for (; p > 0; p -= p&-p){
            chmax(ans, bit[p]);
        }
        return ans;
    }
};

struct pack {
    int a, b, p;
    bool operator < (const pack& other) const {
        return pii(a, b) < pii(other.a, other.b);
    }
};

int main()
{
    fastio;
    int n; cin >> n;
    vector<pack> projects;
    vector<int> val;
    for (int i = 0; i < n; i++){
        int a, b, p; cin >> a >> b >> p;
        projects.push_back({a, b, p});
        val.push_back(a);
        val.push_back(b);
    }
    compress(val);
    for (auto &[a, b, p] : projects){
        a = lower_bound(all(val), a) - val.begin() + 1;
        b = lower_bound(all(val), b) - val.begin() + 1;
    }
    FenwickTree tree(val.size());
    sort(all(projects));
    long ans = 0;
    for (auto [a, b, p] : projects){
        long cur = tree.get(a - 1) + p;
        chmax(ans, cur);
        tree.update(b, cur);
    }
    cout << ans;
    return 0;
}