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

const int N = 2e3 + 1;
int cnt[N];
int a[N][N];

int main()
{
    fastio;
    int T; cin >> T;
    while (T--){
        int n; cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> a[i][0];
        }        
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++) cnt[a[j][i - 1]]++;
            for (int j = 1; j <= n; j++) a[j][i] = cnt[a[j][i - 1]];
            for (int j = 1; j <= n; j++) cnt[j] = 0;
        }
        int Q; cin >> Q;
        while (Q--){
            int x, k; cin >> x >> k;
            chmin(k, n);
            cout << a[x][k] << '\n';
        }
    }
    return 0;
}