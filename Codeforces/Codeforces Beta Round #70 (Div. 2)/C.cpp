/**
 *    author:    hungt1
 *    created:   30-10-2021   16:45:17
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

int main()
{
    fastio;
    int n, m, k; cin >> n >> m >> k;
    if (n % 2 == 0){
        cout << "Marsel";
    }
    else {
        for (int i = 1; i * i <= m; i++){
            if (m % i == 0){
                int x1 = i;
                int x2 = m / i;
                if ((x2 != 1 && x1 >= k) || (x1 != 1 && x2 >= k)) {
                    cout << "Timur";
                    return 0;
                }
            }
        }        
        cout << "Marsel";
    }
    return 0;
}