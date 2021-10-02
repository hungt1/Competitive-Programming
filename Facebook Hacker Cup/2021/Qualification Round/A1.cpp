/**
 *    author:    hungt1
 *    created:   28-08-2021   00:04:24
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

bool isVowel[26];

int main()
{
    fastio;
    isVowel['A' - 'A'] = isVowel['E' - 'A'] = isVowel['I' - 'A'] = isVowel['O' - 'A'] = isVowel['U' - 'A'] = true;
    int T; cin >> T;
    for (int test = 1; test <= T; test++){
        string s; cin >> s;
        int ans = INF;
        auto solve = [&](int p){
            int cnt = 0;
            for (char &c : s){
                if ((c - 'A') == p) continue;
                int x = isVowel[p], y = isVowel[c - 'A'];
                if (x ^ y) cnt++;
                else cnt += 2;
            }
            return cnt;
        };
        for (int i = 0; i < 26; i++){
            chmin(ans, solve(i));
        }
        cout << "Case #" << test << ": " << ans << '\n';       
    }
    return 0;
}