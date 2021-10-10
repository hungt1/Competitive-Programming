/**
 *    author:    hungt1
 *    created:   10-10-2021   16:10:37
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

void solve(){
    int n; cin >> n;
    vector<vector<int>> day(5);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < 5; j++){
            int x; cin >> x;
            day[j].push_back(x);
        }    
    }
    auto check = [&](int fi, int se, int same) -> bool{
        if (fi + same < n/2) return false;
        same -= max(0, n/2 - fi);
        if (se + same < n/2) return false;
        return true;
    };

    for (int i = 0; i < 4; i++){
        for (int j = i + 1; j < 5; j++){
            int fi = 0, se = 0, same = 0;
            for (int k = 0; k < n; k++){
                if (day[i][k] == day[j][k]){
                    if (day[i][k]){
                        same++;
                        continue;
                    }
                    else continue;
                }
                if (day[i][k]) fi++;
                else se++;
            }
            if (check(fi, se, same)){
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";
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