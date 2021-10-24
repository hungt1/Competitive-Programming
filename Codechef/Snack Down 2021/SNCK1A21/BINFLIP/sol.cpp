/**
 *    author:    hungt1
 *    created:   23-10-2021   11:30:48
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
    int T; cin >> T;
    while (T--){
        int n, k; cin >> n >> k;
        if (k == 0){
            cout << "YES\n" << 0 << '\n';
            continue;
        }
        auto solve = [&](int len, vector<int>& ans) -> bool{
            // y - x = k
            // y + x = 2^0 + 2^1 + .. + 2^len
            // x, y >= 0
            long sum = 0;
            for (int i = 0; i <= len; i++) sum += (1 << i);
            if ((sum + k) % 2) return false;
            int y = (sum + k) / 2;
            int x = sum - y;
            if (x < 0) return false;
            int pos = k + 1;
            vector<int> tmp;
            for (int i = 0; i <= len; i++){
                int add = (1 << i);
                if (y >> i & 1){
                    if (tmp.size() == 0){
                        if (pos- add < 1) return false;
                        pos -= add;
                        ans[i] = pos;
                    }
                    else {
                        int curL = pos - (1 << tmp[0]);
                        int curR = pos;
                        pos = curL;
                        if (pos < 0) return false;
                        for (int j = (int)tmp.size() - 1; j >= 0; j--){
                            int k = tmp[j];
                            if (curL - (1 << k) >= 1){
                                curL -= (1 << k);
                                ans[k] = curL;
                            }  
                            else {
                                if (curR + (1 << j) - 1 > n) return false;
                                ans[k] = curR;
                                curR += (1 << j);
                            }
                        }
                        ans[i] = curL;
                        tmp.clear();
                    }
                }
                else {
                    tmp.push_back(i);
                }
            }    
            return true;
        };

        bool found = false;
        for (int i = 0; i <= 30; i++){
            vector<int> ans(i + 1);
            if (solve(i, ans)){
                found = true;
                cout << "YES\n";
                cout << i + 1 << '\n';
                for (int x : ans) {
                    cout << x << '\n';
                }
                break;
            }
        }
        if (!found) cout << "NO\n";
    }   
    return 0;
}