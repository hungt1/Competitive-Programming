/**
 *    author:    hungt1
 *    created:   15-10-2021   00:45:49
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

const int INF = 2e9;
const int MOD = 1e9 + 7;
const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

const int N = 2e6 + 2;
int cnt[N];

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    int ans = 0;
    for (int i = 0; i < n; i++){
        set<int> divisors;
        int z = 0;
        for (int j = 0; j < n; j++){
            if (i != j){
                int x = abs(a[i] - a[j]);
                if (x == 0) z++;
                for (int div = 1; div * div <= x; div++){
                    if (x % div == 0){
                        cnt[div]++;
                        divisors.insert(div);
                        if (x / div != div){
                            cnt[x / div]++;
                            divisors.insert(x / div);
                        }
                    }
                }
            }
        }
        if (z >= n / 2 - 1){
            for (int x : divisors) cnt[x] = 0;
            cout << -1 << '\n';
            return;
        }
        for (int x : divisors){
            if (cnt[x] + z >= n / 2 - 1){
                chmax(ans, x);
            }
            cnt[x] = 0;
        }
    }
    cout << ans << '\n';
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