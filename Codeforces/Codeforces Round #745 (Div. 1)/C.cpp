/**
 *    author:    hungt1
 *    created:   03-10-2021   00:08:36
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

const int N = 2e5 + 1;
const int MAGIC = 450;

int x[N], y[N], start[N];
int cnt[N], f[N][MAGIC];

int main()
{
    fastio;
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> x[i] >> y[i];
    }

    auto updateLong = [&](int s, int u, int v, int val){
        for (; s < m; s += u + v){
            if (s + u < m){
                cnt[s + u] += val;
            }
            if (s + u + v < m){
                cnt[s + u + v] -= val;
            }
        }       
    };

    auto updateShort = [&](int s, int u, int v, int val){
        for (int i = 0; i < v; i++){
            f[u + v][(s + u + i) % (u + v)] += val;
        }
    };

    for (int i = 0; i < m; i++){
        int op, k; cin >> op >> k;
        if (op == 1){
            if (x[k] + y[k] >= MAGIC){
                updateLong(i, x[k], y[k], 1);
            }
            else {
                updateShort(i, x[k], y[k], 1);
            }
            start[k] = i;
        }   
        else {
            if (x[k] + y[k] >= MAGIC){
                for (int s = start[k]; s < m; s += x[k] + y[k]){
                    int l = max(s + x[k], i);
                    int r = s + x[k] + y[k];
                    if (l < r){
                        if (l < m) cnt[l]--;
                        if (r < m) cnt[r]++;
                    }
                }
            }
            else {
                updateShort(start[k], x[k], y[k], -1);
            }
        }
        if (i > 0) cnt[i] += cnt[i - 1];
        int cur = cnt[i];
        for (int x = 2; x < MAGIC; x++){
            cur += f[x][i % x];
        }
        cout << cur << '\n';
    }
    return 0;
}