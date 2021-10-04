/**
 *    author:    hungt1
 *    created:   03-10-2021   22:31:14
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

const int N = 1e3 + 1;
int par[N];
vector<int> other;

int ask(int l, int r){
    set<int> ver;
    for (int i = l; i <= r; i++){
        int x = other[i - 1];
        ver.insert(x);
        ver.insert(par[x]);
    }
    cout << "? " << ver.size() << ' ';
    int i = 0;
    for (int x : ver){
        if (i != 0) cout << ' ';
        cout << x; i++;
    }
    cout << endl;
    int take; cin >> take;
    return take;
}

int main()
{
    int n; cin >> n;
    vector<vector<int>> a(n + 1);
    for (int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        a[u].push_back(v); a[v].push_back(u);
    }
    
    function<void(int, int)> dfs = [&](int p, int u){
        other.push_back(u);
        for (int v : a[u]){
            if (v == p) continue;
            par[v] = u; dfs(u, v); 
        }    
    };

    dfs(0, 1);

    int ans = ask(2, n), ver = -1;
    int l = 2, r = n;
    while (l < r){
        int m = (l + r) / 2;
        if (ask(l, m) == ans){
            ver = other[m - 1];
            r = m;
        }
        else {
            l = m + 1;
            ver = other[l - 1];
        }
    }
    cout << "! " << ver << ' ' << par[ver];   
    return 0;
}