/**
 *    author:    hungt1
 *    created:   04-09-2021   18:49:57
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
    vector<int> a(n);
    for (int &x : a) cin >> x;
    
    deque<int> mx, mn;
    vector<int> F(n, 0);
    int l = 0;
    for (int r = 0; r < n; r++){
        while (mn.size() && a[mn.back()] >= a[r]) mn.pop_back();
        while (mx.size() && a[mx.back()] <= a[r]) mx.pop_back();
        mn.push_back(r); mx.push_back(r);
        while (a[mx.front()] - a[mn.front()] > k){
            l++;
            if (mn.front() < l) mn.pop_front();
            if (mx.front() < l) mx.pop_front();
        }
        F[r] = r - l + 1;
    }

    int ans = F[0];
    for (int i = 1; i < n; i++){
        if (i - F[i] >= 0) chmax(ans, F[i] + F[i - F[i]]);
        else chmax(ans, F[i]);
        chmax(F[i], F[i - 1]);
    }    
    cout << ans;
    return 0;
}
