/**
 *    author:    hungt1
 *    created:   28-08-2021   00:26:07
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
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

int main()
{
    fastio;
    int T; cin >> T;
    for (int test = 1; test <= T; test++){
        string s; cin >> s;
        vector<vector<int>> dis(26, vector<int> (26, INF));
        int K; cin >> K;
        for (int i = 0; i < 26; i++) dis[i][i] = 0;
        for (int i = 0; i < K; i++){
            char x, y; cin >> x >> y;
            dis[x - 'A'][y - 'A'] = 1;
        }
        for (int k = 0; k < 26; k++){
            for (int u = 0; u < 26; u++){
                for (int v = 0; v < 26; v++){
                    chmin(dis[u][v], dis[u][k] + dis[k][v]);
                }
            }
        }
        int ans = INF;
        for (int p = 0; p < 26; p++){
            int cnt = 0;
            for (char &c : s){
                cnt += dis[c - 'A'][p];
                if (cnt >= INF) break;
            }
            chmin(ans, cnt);
        }
        cout << "Case #" << test << ": " << (ans == INF ? -1 : ans) << '\n';       
    }
    return 0;
}