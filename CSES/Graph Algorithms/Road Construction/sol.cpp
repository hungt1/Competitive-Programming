/**
 *    author:    hungt1
 *    created:   14-12-2021   11:02:24
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

struct DSU {
    vector<int> lab;
    int n, components, largestComponents;

    DSU(int n) : n(n) {
        lab.resize(n + 1, -1);
        components = n;
        largestComponents = 1;
    }
    
    int get(int u){
        return (lab[u] < 0 ? u : lab[u] = get(lab[u])); 
    }
    
    int size(int u){
        return -lab[get(u)];
    }

    bool same(int u, int v){
        return get(u) == get(v);
    }

    bool unite(int x, int y){
        x = get(x); y = get(y);
        if (x == y) return 0;
        if (lab[x] > lab[y]) swap(x, y);
        lab[x] += lab[y]; lab[y] = x;
        components--; 
        chmax(largestComponents, -lab[x]);
        return 1;
    }
};

int main()
{
    fastio;
    int n, m; cin >> n >> m;
    DSU dsu(n);
    while (m--){
        int u, v; cin >> u >> v;
        dsu.unite(u, v);
        cout << dsu.components << ' ' << dsu.largestComponents << '\n';
    }
    return 0;
}