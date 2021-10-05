/**
 *    author:    hungt1
 *    created:   03-10-2021   12:54:47
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

void solve(int n, int a, int b, int c){
    if (n == 1){
        cout << a << ' ' << c << '\n';
        return;
    }
    solve(n - 1, a, c, b);
    cout << a << ' ' << c << '\n';
    solve(n - 1, b, a, c);
}

int main()
{
    fastio;
    int n; cin >> n;
    cout << (1 << n) - 1 << '\n';
    solve(n, 1, 2, 3);
    return 0;
}