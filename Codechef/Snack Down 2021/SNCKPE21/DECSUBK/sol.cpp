/**
 *    author:    hungt1
 *    created:   21-11-2021   22:50:08
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

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    vector<int> ans;
    sort(all(a));
    auto can = [&](int pos) -> bool {
        vector<int> b;
        for (int x : ans) b.push_back(x);
        b.push_back(a[pos]);
        for (int i = (int)a.size() - 1; i >= 0; i--){
            if (i != pos) {
                b.push_back(a[i]);
            }
        }
        int len = b.size();
        vector<int> dp(len, 0);
        for (int i = 0; i < len; i++){
            dp[i] = 1;
            for (int j = 0; j < i; j++){
                if (b[j] <= b[i]){
                    chmax(dp[i], dp[j] + 1);
                }
            }
        }
        return (*max_element(all(dp)) <= k);
    };

    while (ans.size() < n){
        bool found = false;
        for (int i = 0; i < a.size(); i++){
            if (can(i)){
                ans.push_back(a[i]);
                a.erase(a.begin() + i);
                found = true;
                break;
            }
        }
        if (!found){
            cout << -1 << '\n';
            return;
        }
    }  
    for (int x : ans) cout << x << ' '; cout << '\n';
}

int main()
{
    fastio;
    int T; cin >> T;
    while (T--){
        solve();
    }
    return 0;
}