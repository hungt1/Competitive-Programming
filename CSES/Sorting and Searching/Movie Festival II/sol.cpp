/**
 *    author:    hungt1
 *    created:   02-11-2021   11:07:20
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
    int n, k; cin >> n >> k;
    vector<pii> a(n);
    for (pii &x : a) cin >> x.second >> x.first;
    sort(all(a));
    multiset<int> s; int ans = 0;
    for (auto [r, l] : a){
        auto it = s.upper_bound(l);
        if (it != s.begin()){
            ans++; it--;
            s.erase(it);
            s.insert(r);
        }
        else if ((int)s.size() < k) {
            s.insert(r); ans++;
        }
    }
    cout << ans;
    return 0;
}