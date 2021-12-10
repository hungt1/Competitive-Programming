/**
 *    author:    hungt1
 *    created:   01-12-2021   21:37:18
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

int get(int x){
    int cnt = 0;
    for (; x > 0; x /= 10, cnt++);
    return cnt;
}

int main()
{
    fastio;
    int T; cin >> T;
    while (T--){
        int x1, p1, x2, p2; cin >> x1 >> p1 >> x2 >> p2;
        int a = get(x1) + p1;
        int b = get(x2) + p2;
        if (a < b){
            cout << "<";
        }        
        else if (a > b){
            cout << ">";
        }
        else {
            while (get(x1) < get(x2)) x1 *= 10;
            while (get(x2) < get(x1)) x2 *= 10;
            cout << (x1 < x2 ? "<" : (x1 == x2) ? "=" : ">");
        }
        cout << '\n';
    }
    return 0;
}