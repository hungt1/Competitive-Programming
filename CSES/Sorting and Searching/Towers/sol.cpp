/**
 *    author:    hungt1
 *    created:   13-10-2021   19:53:42
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
    int n; cin >> n;
    multiset<int> s;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        x = -x;
        auto it = s.lower_bound(x);
        if (it == s.begin()) s.insert(x);
        else {
            it--;
            s.erase(it);
            s.insert(x);
        }
    }
    cout << s.size();
    return 0;
}