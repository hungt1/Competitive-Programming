/**
 *    author:    hungt1
 *    created:   14-09-2021   14:15:03
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

const int N = 35;
int n, x[N], y[N];
int X, Y, U, V;
long ans;
map<pii, int> cnt;

void solve(int l, int r, int op){
    if (l > r) {
        cnt[pii(0, 0)]++;
        return;
    }
    for (int i = 0; i < 2; i++){
        X += x[l] * i;
        Y += y[l] * i;
        if (l == r){
            if (op == 1) cnt[pii(X, Y)]++;
            else {
                ans += cnt[pii(U - X, V - Y)];
            }
        }
        else solve(l + 1, r, op);
        X -= x[l] * i;
        Y -= y[l] * i;
    }
}

int main()
{
    fastio;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> x[i] >> y[i];
    }    
    cin >> U >> V;
    solve(1, n / 2, 1); solve(n / 2 + 1, n, 2);
    cout << ans;
    return 0;
}